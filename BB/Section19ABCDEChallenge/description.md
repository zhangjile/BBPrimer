Section 19
Challenge 2
Automated Grader

Write a program that reads a file named 'responses.txt" that contains the answer key for a quiz
as well as student responses for the quiz.

The answer key is the first item in the file.
Student1 name
Student1 responses
Student2 name
Student2 responses
. . .

Here is a sample file.

ABCDE   //string Metrics;
Frank   //string Name;                 
ABCDE   //string Answers    if(Answers[i] == Metrics[i]) ++Points;               
Larry
ABCAC
Moe
BBCDE
Curly
BBAAE
Michael
BBCDE

You should read the file and display:
Each student's name and score (#correct out of 5)
At the end, the class average should be displayed
You may assume that the data in the file is properly formatted

## laugh out loud, if not formatted, error is certain to come out.

Program should output to the console the following:
Student                     Score   //void DisplayHeader ();
----------------------------
Frank                             5     // int StudentScore(string n, string a);
Larry                              3
Moe                              4
Curly                             2
Michael                         4
---------------------------
Average score            3.6        //Average = TotalScore/StudentCount

## extention
how to format data file?

