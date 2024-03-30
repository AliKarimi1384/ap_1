/*
Advanced programming course
Exercise number 1_2
Ali Karimi
Github account: https://github.com/AliKarimi1384
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class myclass
{
public:
    bool compare_results(int num)
    {
        string _file_out;
        string _file_userout;
        _file_out = result(true, num);
        _file_userout = result(false, num);
        if (_file_out.compare(_file_userout) == 0)
        {
            return true;
        }
        return false;
    }

private:
    string path(int num, bool is_out)
    {
        string directory;
        if (is_out)
        {
            directory = "out\\";
        }
        else
        {
            directory = "userout\\";
        }
        return directory + "Output" + to_string(num) + ".txt";
    }
    string result(bool flag, int num)
    {
        string res;
        string temp;
        fstream file;
        file.open(path(num, flag));
        if (!file.is_open())
        {
            cout << "Error: There was a problem while opening the files. \nMake sure that output files, userout and user directories are available and try again.";
            exit(0);
        }
        while (!file.eof())
        {
            getline(file, temp);
            res += temp + "\n";
        }
        file.close();
        return res;
    }
};
int main()
{
    double count = 0;
    myclass obj;
    // we know that there are 10 outputs
    for (int i = 1; i <= 10; i++)
    {
        if (obj.compare_results(i))
        {
            ++count;
        }
    }
    double result = count / 10.0 * 100.0;
    cout << "The final percentage is " << result << '%';
    return 0;
}