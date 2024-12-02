#include <vector>
#include <fstream>
#include <iostream>
#include <string>

const std::string PATH = "../PuzzleInput.txt";

std::vector<int> parse_line( const std::string& line )
{
    std::string num;
    std::vector<int> result;

    for ( size_t i = 0; i < line.size(); ++i ) {
        if ( line[ i ] == ' ' ) {
            result.push_back( std::atoi( num.data() ) );
            num = "";
        } else {
            num.push_back( line[ i ] );
        }
    }

    result.push_back( std::atoi( num.data() ) );
    return result;
}

// assumes lines have more than one number
int check_numbers( const std::vector<int>& nums )
{
    bool increasing = nums[ 0 ] < nums[ 1 ];

    for ( size_t i = 0; i < nums.size() - 1; ++i ) {
        if ( ( increasing && nums[ i ] >= nums[ i + 1 ] )
             || ( !increasing && nums[ i ] <= nums [ i + 1 ] )
             || ( std::abs( nums[ i ] - nums[ i + 1 ] ) > 3 ) ) {
            
            return 0;
        }
    }

    return 1;
}

int main()
{
    std::ifstream file{ PATH };
    std::string line;
    int result = 0;

    while ( std::getline( file, line ) )
        result += check_numbers( parse_line( line ) );
    
    std::cout << "Result: " << result << '\n';

    return 0;
}