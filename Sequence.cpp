#include "Sequence.h"
#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
using namespace std;

Sequence::Sequence(string filename)
{
        char a[100];
        strcpy(a, filename.c_str());
        freopen(a, "r", stdin);
        string line1;
        while(getline(cin,line1))
        {
                line += line1;
        }
}

int Sequence::length()
{
        int s = 0;
        s = (int)line.size();
        return s;
}

int Sequence::numberOf(char base)
{
        int a = 0;
        int t = 0;
        int c = 0;
        int g = 0;
        for(int i = 0; i < (int)line.size(); i++)
        {
                if (line[i] == 'A')
                        a++;
                else if (line[i] == 'T')
                        t++;
                else if (line[i] == 'C')
                        c++;
                else if (line[i] == 'G')
                        g++;
        }
       if (base == 'A')
                return a;
        else if (base == 'T')
                return t;
        else if (base == 'C')
                return c;
        else if (base == 'G')
                return g;
}

string Sequence::longestConsecutive()
{
        int A1 = 1;
        int T1 = 1;
        int C1 = 1;
        int G1 = 1;
        int A2 = 1;
        int T2 = 1;
        int C2 = 1;
        int G2 = 1;
        string a1 = "A";
        string t1 = "T";
        string c1 = "C";
        string g1 = "G";
        string a2 = "";
        string t2 = "";
        string c2 = "";
        string g2 = "";
        for (int i = 1; i < (int)line.size(); i++)
        {
                if (line[i - 1] != line[i])
                        continue;
                else if (line[i - 1] == 'A' && line[i] == 'A')
                {
                        a1 += "A";
                        A1++;
                        if (line[i + 1] != 'A')
                        {
                                if (A2 <= A1)
                                {
                                        a2 = a1;
                                        A2 = A1;
                                }
                                a1 = "A";
                                A1 = 1;
                        }
                }
                else if (line[i - 1] == 'T' && line[i] == 'T')
                {
                        t1 += "T";
                        T1++;
                        if (line[i + 1] != 'T')
                        {
                                if (T2 <= T1)
                                {
                                        t2 = t1;
                                        T2 = T1;
                                }
                                t1 = "T";
                                T1 = 1;
                        }
                }
                else if (line[i - 1] == 'C' && line[i] == 'C')
                {
                        c1 += "C";
                        C1++;
                        if (line[i + 1] != 'C')
                        {
                                if (C2 <= C1)
                                {
                                        c2 = c1;
                                        C2 = C1;
                                }
                                c1 = "C";
                                C1 = 1;
                        }
                }
                else if (line[i - 1] == 'G' && line[i] == 'G')
                {
                        g1 += "G";
                        G1++;
                        if (line[i + 1] != 'G')
                        {
                                if (G2 <= G1)
                               {
                                        g2 = g1;
                                        G2 = G1;
                                }
                                g1 = "G";
                                G1 = 1;
                        }
                }
        }

        int m = A2;
        if (m < T2)
                m = T2;
        if (m < C2)
                m = C2;
        if (m < G2)
                m = G2;

        if (m = A2)
                return a2;
        if (m = T2)
                return t2;
        if (m = C2)
                return c2;
        if (m = G2)
                return g2;
}

int compare(const void *p1, const void *p2)
{
        return strcmp(*(char* const *)p1, *(char* const*)p2);
}

int sc(char *a, char *b)
{
        int x = 0;
        while (*a && (*a++ == *b++))
                ++x;
        return x;
}

string Sequence::longestRepeated()
{
        int L = 0;
        L = (int)line.size();
        char* b=new char[1200000];
        strcpy(b, line.c_str());
        char* *c=new char*[1200000];
        for(int i = 0; i < L; ++i)
                c[i] = &b[i];
        int m = 0;
        int mc = 0;
        int n = 0;
        qsort(c, L, sizeof(char*), compare);
        for (int i = 0; i < L - 1; ++i)
        {
                n = sc(c[i], c[i + 1]);
                if (n > mc)
                {
                        mc = n;
                        m = i;
                }
        }
        string s = c[m];
        string lr;
        for (int i = 0; i < mc; ++i)
        {
                lr += s[i];
        }
        delete []b;
        delete []c;
        return lr;
}
