 #include <iostream>
#include <vector>
#include <iterator>
using namespace std;

vector<int> swapStrInt(string str)
{
	vector<int> vec;
	int num = 0;
	for (int i = 0; i < str.size(); i++)
	{

		num = str[i] - '0';
		vec.push_back(num);
		cout << vec[i] << endl;
	}
	return vec;
}

vector<int> sumVec(vector<int>& a, vector<int>& b)
{
	vector<int> result;
	int num = 0;
	int carry = 0;
	const int base = 10;
	for (int i = 1; i <= a.size(); i++)
	{
		for (int j = 0; j < 1; j++)
		{
			num = carry + a[a.size() - i] + b[a.size() - i];
			carry = num / base;
			num %= base;
			result.insert(result.cbegin(), num);
		}
	}
	if (carry != 0) {
		result.insert(result.cbegin(), carry);
	}
	return result;
}
vector<int> minusVec(vector<int>& a, vector<int>& b)
{
	vector<int> result;
	int num = 0;
	const int base = 10;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] > b[i])
		{
			for (int j = 1; j <= a.size(); j++)
			{
				if (j < a.size())
				{
					a[a.size() - j - 1]--;
					num = base + a[a.size() - j];
				}
				else
				{
					num = a[a.size() - j];
				}
				num -= b[a.size() - j];
				if (num / base > 0)
				{
					a[a.size() - j - 1]++;
					num %= base;
				}
				result.insert(result.cbegin(), num);
			}
			break;
		}

	}
	for (int j = 0; j < result.size(); j++)
	{
		if (result[j] == 0)
			result.erase(result.begin());
		else
			break;
	}
	return result;
}




int main()
{
	string str1 = "222";
	string str2 = "115";
	vector<int> vector1 = swapStrInt(str1);
	vector<int> vector2 = swapStrInt(str2);
	vector<int> res = minusVec(vector1, vector2);


	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}


	system("pause");
	return 0;
}
