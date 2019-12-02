#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <sstream>
#include "isSquareMatrix.h"

TEST_CASE("Basic matrix computations", "(matrix)"){
    CHECK(isSquareMatrix("[[]]"));
    CHECK(isSquareMatrix("[[1,2,3][4,5,6][1,2,3]]"));
    CHECK(isSquareMatrix("[[1,2,3,4][4,5,6,4][1,2,3,4][6,5,3,2]]"));
    CHECK(!isSquareMatrix("[[1,2][1,2,2]]"));
    CHECK(!isSquareMatrix("[[1,2,4][1,2,2"));
    CHECK(!isSquareMatrix("[[1,2,4]]"));
    CHECK(!isSquareMatrix("[[1,2]]xxx"));
    CHECK(!isSquareMatrix("[[1,[1,2]]"));
    CHECK(!isSquareMatrix("[[1,2][asd]]"));
    CHECK(!isSquareMatrix("adsa[[1]]"));
    CHECK(!isSquareMatrix("[[1,2]asa[1,2]]"));
    CHECK(!isSquareMatrix("[[1][[1]"));
}

bool isSquareMatrix(const std::string &str){
    std::stringstream inputstrm(str);

    if(str == "[[]]")
        return true;

    int number = 0;
    char c;
    int col = 0;
    int colnum = 0;
    int rows = 0;

    inputstrm >> c;
    if( !inputstrm.good() || c!= '[')
        return false;

    inputstrm >> c;
    if( !inputstrm.good() || c!= '[')
        return false;

    // Lukee rivi rivilt� ja tarkistaa
    while(c!=']'){

        do{
            inputstrm >> number;
            if( !inputstrm.good())
                return false;

            inputstrm >> c;
            if(c != ',' && c != ']')
                return false;

            col++;

        }while(c!=']');

        rows++;
        if(rows == 1)
            colnum = col;

        if(colnum != col)
            return false;
        col = 0;

        inputstrm >> c;
        if(inputstrm.eof())
            return false;

    }

    // Tarkistaa  onko neli�matriisi
    if(rows != colnum)
        return false;

    // Onko merkkeja sulkujen jalkeen
    std::string tail;
    inputstrm >> tail;
    if(tail != "")
        return false;

    return true;
}
