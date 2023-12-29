#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    system("cls");
    unordered_map<string, int> mp;

    /*In case of an unordered map we can insert, delete or search in constant time complexity whereas for ordered map insertion, deletion and seraching happens in logn time complexity*/

    // insertion methods in a map
    pair<string, int> p = make_pair("scorpio", 9);
    mp.insert(p);

    pair<string, int> p2("baleno", 2);
    mp.insert(p2);

    mp["fortuner"] = 10;

    // accessing values from the map
    cout << mp.at("fortuner");
    cout << mp["fortuner"];

    // searching values in map - tells if a key exists or not
    cout << mp.count("scorpio");
    if (mp.find("fortuner") != mp.end())
        cout << "found";
    else
        cout << "not found";

    // printing the size of the map
    cout << "\n";
    cout << "Size of map is : " << mp.size();
    cout << mp["hummer"]; // not present but now  an entry will be created so size of map increases by 1
    cout << "\n";
    cout << "Size of map is : " << mp.size();

    return 0;
}