//
//  main.cpp
//  Anagram | Assignment 1
//
//  Created by Arnab Paul on 07/08/18.
//  Copyright © 2018 Arnab Paul. All rights reserved.
//

#include<iostream>
#include<string.h>
#include<stdio.h>
#include <fstream>
using namespace std;


int anagram(string str1, string str2) // Comparing two strings for anagram
{
    int a, i, flag = 0,  x[26] = {0}, y[26] = {0};
    for(i = 0; str1[i] != '\0'; i++)
        x[str1[i] - 'a']++;     //Comparing ASCII Values and incrementing the cell values accordingly
    for(i = 0; str2[i] != '\0'; i++)
        y[str2[i] - 'a']++;
    for (i = 0; i < 26; i++)
    {
        if (x[i] != y[i])
            flag = 1;
    }
    if (flag == 1)
        a = 0;
    else
        a = 1;
    return a;
}

int main()
{
    string str[30000];
    int a = 0;
    int n;
    int i, j, l_excl = 0,l_incl = 0, m, size = 0, size1, c; //counter intialization
    ifstream infile;          //Reading input variables
    infile.open("input.txt");
    infile>>n;
    for(i = 0; i<n; i++){
        infile>>str[i];
    }
 
//The idea here is to store the anagrams in an n*n array where row denotes the index of the string and columns contains the indexes of the anagrams
    int temp_excl[n];
    int temp_incl[n];
    for(i = 0;i<n;i++){
        temp_incl[i] = {-1};    //Initializing with random negative values to remove confusion
        temp_excl[i] = {-1};
    }
    int arr[n][n];  //Storing the indexes of the anagrams
    for(i = 0; i<n;i++){
        for(j= 0; j<n; j++){
            arr[i][j] = {-1};
        }
    }
    
    //temp_excl stores the anagrams of i indexes
    //temp_incl stores the i indexes which have anagrams
    for(i = 0;i<n;i++){
        int flag = 0;
        int flag1 = 0;
        int k = 0;
        for(m = 0; m<n; m++){
            if(temp_excl[m]==i){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            continue;
        }
        for (j = 0;j<n; j++){
            
            if(i==j){
                continue;
            }
            a = anagram(str[i], str[j]);
            if(a==1){
                flag1 = 1;
                temp_excl[l_excl] = j;
                arr[i][k] = j;
                l_excl++;
                k++;
                
                }
            }
        if(flag1==1){
            temp_incl[l_incl] = i;
            l_incl++;
        }
        
    }
    
    
    for(i=0;i<n;i++){
        if(temp_incl[i]>=0){
            size++;            //Size stores the sets of anagrams
        }
    }
    cout<<size<<endl;
    
    for(i = 0; i<size; i++){
        size1 = 1;
        for(j=0;j<n;j++)
        {
            if(arr[temp_incl[i]][j] >= 0){
                size1++;
            }
            }
        cout<<size1<<endl;
        
        cout<<str[temp_incl[i]]<<endl;
        for(c=0;c<n;c++){
            
            if(arr[temp_incl[i]][c]>=0){
                cout<<str[arr[temp_incl[i]][c]]<<endl;
            }
        }
    }
    return 0;
}

