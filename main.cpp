#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const pair<char, int> &l, const pair<char, int> &r){ 
    return (l.second > r.second); 
} 

int main()
{
    char encoded;
    string line;
    istringstream ss;
    int cases;
    unordered_map<char, int> map;
    unordered_map<char, char> decoderMap;
    vector<pair<char, int>> encoder, decoder;

    getline(cin, line);
    ss.str(line);
    ss >> cases;
    ss.clear();

    for (int i = 0; i < cases; i++)
    {
        getline(cin, line);
        getline(cin, line);

        for (auto it = line.begin(); it != line.end(); it++)
        {
            map[*it] += 1;
        }

        copy(map.begin(), map.end(), back_inserter<vector<pair<char, int>>>(encoder));
        sort(encoder.begin(), encoder.end(), comp);
        map.clear();

        getline(cin, line);

        for (auto it = line.begin(); it != line.end(); it++)
        {
            map[*it] += 1;
        }

        copy(map.begin(), map.end(), back_inserter<vector<pair<char, int>>>(decoder));
        sort(decoder.begin(), decoder.end(), comp);
        
        
        for (int i = 0; i < encoder.size(); i++)
        {
            decoderMap[decoder[i].first] = encoder[i].first;
        }
        
        for (auto it = line.begin(); it != line.end(); it++)
        {
            cout << decoderMap[*it];
        }
        
        if(i == cases-1){
            cout << endl;
        }
        else{
            cout << endl << endl;
        }
        decoder.clear();
        encoder.clear();
        decoderMap.clear();
        map.clear();
    }
    return EXIT_SUCCESS;
}