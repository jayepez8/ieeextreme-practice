#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <limits>
#include <cstring>

using namespace std;

const int INF = numeric_limits<int>::max() - 10e6;

int main(int argc, char const *argv[])
{
    int nBooks = 1, nTopics = 0, bookTime, bookValue;
    vector<string> topics;
    vector<pair<int, int>> books;
    string topic, line;

    //Input data.
    while (getline(cin, line))
    {
        nBooks++;
        bookValue = 0;
        istringstream iss(line);
        iss >> bookTime;
        while (iss >> topic)
        {
            int d;
            vector<string>::iterator it = find(topics.begin(), topics.end(), topic);
            if (it == topics.end())
            {
                topics.push_back(topic);
                d = nTopics;
                nTopics++;
            }
            else
            {
                d = distance(topics.begin(), it);
            }
            bookValue += 1 << d;
        }
        books.push_back(pair<int, int>{bookValue, bookTime});
    }

    // Show data.
    //for (auto p : books)
    //{
    //    cout << p.first << " " << p.second << endl;
    //}

    // Solve.
    //Create a dp matrix.
    vector<vector<int>> table;
    vector<int> row;
    table.resize(2);
    row.resize(1 << nTopics);
    fill(row.begin(), row.end(), INF);
    row[0] = 0;
    fill(table.begin(), table.end(), row);

    // Delete this
    //for (int i = 0; i < table.size(); i++)
    //{
    //    for (int j = 0; j < table[i].size(); j++)
    //    {
    //        cout << table[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    //Solving.

    for (int i = 1; i < nBooks; i++)
    {
        bookValue = books[i - 1].first;
        bookTime = books[i - 1].second;
        int newBookTime, newBookValue;

        for (int j = 0; j < (1 << nTopics); j++)
        {
            newBookValue = j | bookValue;
            newBookTime = table[0][j] + bookTime;

            table[1][newBookValue] = min(table[1][newBookValue], newBookTime);
        }

        //for (int i = 0; i < table.size(); i++)
        //{
        //    for (int j = 0; j < table[i].size(); j++)
        //    {
        //        cout << table[i][j] << " ";
        //    }
        //    cout << endl;
        //}
        //cout << endl;
        table[0] = table[1];
        // table[1] = row;
    }

    // Delete this
    // for (int i = 0; i < table.size(); i++)
    // {
    //     for (int j = 0; j < table[i].size(); j++)
    //     {
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // Show Result.
    cout << table[1][(1 << nTopics) - 1] << endl;

    return 0;
}
