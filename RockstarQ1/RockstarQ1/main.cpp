#include <iostream>
#include <string>

int solution2(std::string& S)
{
	//					---- Brief explanation of my thought process ----
	//The question does not explicitly ask for any string manipulation so my first attempt went down the wrong path.
	//Abstracting the question I just need to handle 2 special cases, if a string is empty and if there are 3 a's in a row.
	//Once they are handled a loop can start that walks through the string increasing or decreasing an int counter.
	
	//							---- Time & Space Complexity ----
	//This solution is O(n) in time complexity where n is the length of the string and O(1) in space complexity because the amount of
	//variables used do not scale with the input


	int count = 2;//Assuming that the first letter won't be a, so start count at 2 as if we inserted the two char's
	if(S == "")//Special Case #1 An empty string
	{
		//if the string is empty we should return nothing on the count
		return 0;
	}

	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == 'a' && S[i + 1] == 'a' && S[i + 2] == 'a')//Special Case #2 If there is a triple aaa in string return -1 
		{
			return -1;
		}
		if (S[i] == 'a')//if you're on an 'a' decrement the count
		{
			count--;
		}
		else 
		{
			count += 2; //otherwise increase the count by two as if two more 'a's were inserted into the string
		}
	}
	return count;
}


int solution(std::string& S)
{
	std::string a = "a";//this will be added to the string
	int count = 0;//count how many "a"'s are added
	//sort special case #1 if the string is just "aa"
	if (S == "aa")
	{
		return 0;//cannot add anymore
	}
	

	//loop into the string to check chars
	for (int i = 0; i < S.size(); i++)
	{
		if (S.substr(i, i+2) == "aaa")//sorting special case #3 if any part of the string is aaa it should return -1
		{
			return -1;
		}
		if (S[i] == 'a' && S[i + 1] == 'a' && S[i + 2] == 'a')//single '' because checking just char 
		{
			return -1;//there is a triple aaa in string so no continuing return -1 Special Case #2
		}
		if(S[i] == 'a' && S[i + 1] == 'a')//two a's in a row
		{
			i++;
			continue;
		}
		else if (S[i] != 'a' && S[i + 1] != 'a')//we have a gap, insert
		{
			S.insert(i, "aa");
			count += 2;
			i+=2;
		}
		else if(S[i] != 'a' && S[i+1] == 'a' && S[i+2] != 'a')//not on an a but the next one is an a and the one after is not
		{
			S.insert(i, "a");
			count++;
			i+=2;
		}
	}

	std::cout << S << std::endl;
	return count;
}


int main()
{
	std::string first = "aabab";//algo should return 3 because a string "aabaabaa" can be made
	std::string aa = "aa";//to check special case #1
	std::string aaa = "aaa";//checking special case #2
	std::string baaa = "baaa";//special case #3
	std::string dog = "dog";//solution should return 8 because a string "aadaaoaagaa" can be made
	int solve = solution2(aa);
	std::cout << solve << std::endl;
	int solve2 = solution2(aaa);
	std::cout << solve2 << std::endl;
	int solve3 = solution2(baaa);
	std::cout << solve3 << std::endl;
#if 1
	int solveFirst = solution2(first);
	std::cout << solveFirst << std::endl;
	int solveDog = solution2(dog);
	std::cout << solveDog << std::endl;
#endif
	return 0;
}