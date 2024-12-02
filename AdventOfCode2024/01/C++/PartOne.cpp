#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

const std::string PATH = "../PuzzleInput.txt";

void parse_file( std::vector<int>& left, std::vector<int>& right )
{
    std::ifstream file{ PATH };
    std::string line;

    while ( std::getline( file, line ) ) {
        const int space_idx = line.find( ' ' );
        const std::string l = line.substr( 0, space_idx );
        const std::string r = line.substr( space_idx + 1, line.length() );

        left.push_back( std::atoi( l.data() ) );
        right.push_back( std::atoi( r.data() ) );
    }
}

int solve( const std::vector<int>& left, const std::vector<int>& right )
{
    int sum = 0;
    for ( int i = 0; i < left.size(); ++i ) {
        sum += std::abs( left[ i ] - right[ i ] );
    }
    return sum;
}

int main()
{
    std::vector<int> left{};
    std::vector<int> right{};

    parse_file( left, right );

    std::sort( left.begin(), left.end() );
    std::sort( right.begin(), right.end() );

    std::cout << "Result: " << solve( left, right ) << '\n';

    return 0;
}
