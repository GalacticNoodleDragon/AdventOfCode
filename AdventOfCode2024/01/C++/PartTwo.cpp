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
        const size_t space_idx = line.find( ' ' );
        const std::string l = line.substr( 0, space_idx );
        const std::string r = line.substr( space_idx + 1, line.length() );

        left.push_back( std::atoi( l.data() ) );
        right.push_back( std::atoi( r.data() ) );
    }
}

int solve( const std::vector<int>& left, const std::vector<int>& right )
{
    size_t l_idx = 0;
    size_t r_idx = 0;
    int count = 0;
    int sum = 0;

    while ( l_idx < left.size() && r_idx < right.size() ) {
        if ( left[ l_idx ] < right[ r_idx ] ) {
            ++l_idx;
        } else if ( left[ l_idx ] > right[ r_idx ] ) {
            ++r_idx;
        } else {
            while ( left[ l_idx ] == right[ r_idx ] && r_idx < right.size() ) {
                ++count;
                ++r_idx;
            }
            sum += left[ l_idx ] * count;
            count = 0;
        }
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
