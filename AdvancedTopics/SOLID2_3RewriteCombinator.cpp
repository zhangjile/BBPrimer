// open closed principle

// open for extension, closed for modification

#include <string>
#include <vector>
#include <iostream>
using namespace std;

enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product
{
  string name;
  Color color;
  Size size;
};


template <typename T> struct Specification
{
  virtual ~Specification() = default;
  virtual bool is_satisfied(T* item) const = 0;
};

template <typename T> struct Filter
{
  virtual vector<T*> filter(vector<T*> items,
                            Specification<T>& spec) = 0;
};

struct BetterFilter : Filter<Product>
{
  vector<Product*> filter(vector<Product*> items,
                           Specification<Product> &spec) override
  {
    vector<Product*> result;
    for (auto& p : items)
      if (spec.is_satisfied(p))
        result.push_back(p);
    return result;
  }
};

struct ColorSpecification : Specification<Product>
{
  Color color;

  ColorSpecification(Color color) : color(color) {}

  bool is_satisfied(Product *item) const override {
    return item->color == color;
  }
};

struct SizeSpecification : Specification<Product>
{
  Size size;

  explicit SizeSpecification(const Size size)
    : size{ size }
  {
  }


  bool is_satisfied(Product* item) const override {
    return item->size == size;
  }
};

// rewrite AndSpecification, the combinator, good practice:)
struct AndSpecification : Specification<Product>
{
  const Specification<Product>& first;
  const Specification<Product>& second;

  AndSpecification(const Specification<Product>& first, const Specification<Product>& second) 
    : first(first), second(second) {}

  bool is_satisfied(Product *item) const override {
    return first.is_satisfied(item) && second.is_satisfied(item);
  }
};

AndSpecification operator&&
  (const Specification<Product>& first, const Specification<Product>& second)
{
  return { first, second };
}


int main()
{
  Product apple{"Apple", Color::green, Size::small};
  Product tree{"Tree", Color::green, Size::large};
  Product house{"House", Color::blue, Size::large};

  const vector<Product*> all { &apple, &tree, &house };

  BetterFilter bf;
  ColorSpecification green(Color::green);
  auto green_things = bf.filter(all, green);
  for (auto& x : green_things)
    cout << x->name << " is green\n";


  SizeSpecification large(Size::large);
  AndSpecification green_and_large(green, large);

  auto big_green_things = bf.filter(all, green_and_large);
  auto spec = large && green;
  for (auto& x : bf.filter(all,spec))
    cout << x->name << " is green and large\n";

  return 0;
}
