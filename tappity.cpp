#include "tappity.h"
/**
 * Class for tappity
**/

//Constructor sets the reference phrase
tappity::tappity(std::string reference)
{
  this->reference = reference;
  input = "";
}

//Provide the input to be compared to the reference. Before this 
//function is called, the input should be considered an empty string
void tappity::entry(std::string input)
{
  this->input = input;
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference()
{
  return abs(reference.length()-input.length());
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each 
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function 
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy()
{
  double counter = 0.0;
  int shortest = (reference.length() < input.length()) ? reference.length() : input.length();
  int longest = (reference.length() > input.length()) ? reference.length() : input.length();
  for (int i = 0; i < shortest; i++) {
    if (reference[i] == input[i])
      counter++;
  }
  double score = 100.0 * (counter/longest);
  if (longest == 0)
    return 100;
  else
    return score;
}
