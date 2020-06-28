#include "str.h"
inline
StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}
inline
StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
   
}