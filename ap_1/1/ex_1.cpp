/*
Advanced programming course
Exercise number 1_1
Ali Karimi
Github account: https://github.com/AliKarimi1384
*/
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;
class myclass
{
public:
    myclass()
    {
        srand(time(0));
        CreateDirectory("in", NULL);
    }
    void txt_generator(int file_num)
    {
        ofstream file(file_name(file_num));
        file << test_case();
        file.close();
    }

private:
    int randint(int first_num, int second_num)
    {
        int random_num = 0;
        for (int i = 0; i < 20; i++)
        {
            random_num += rand();
        }
        int temp = second_num - first_num;
        return random_num % temp + first_num;
    }
    string file_name(int num)
    {
        string temp = "in\\input" + to_string(num) + ".txt";
        return temp;
    }
    string test_case()
    {
        int n = randint(2, 100001);
        int m = randint(0, 500001);
        string result = to_string(n) + " " + to_string(m) + "\n";
        int u, v;
        for (int i = 0; i < m; i++)
        {
            v = randint(2, n + 1);
            u = randint(1, v);
            result += to_string(u) + " " + to_string(v) + "\n";
        }
        return result;
    }
};
int main()
{
    myclass obj = myclass();
    for (int i = 1; i <= 10; i++)
    {
        obj.txt_generator(i);
    }
    cout << "Test cases successfully generated";
    return 0;
}