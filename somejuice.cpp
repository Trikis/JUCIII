#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>

enum Operation {encoding , decoding};


class StreamProcessor{
    private:
        std::istream& i_stream;
        std::ostream& o_stream;
    public:
        StreamProcessor(std::istream& _i_stream = std::cin, std::ostream& _o_stream = std::cout) : i_stream(_i_stream) , o_stream(_o_stream) {}
        std::istream& get_istream() {
            return i_stream;
        }

        std::ostream& get_ostream(){
            return o_stream;
        }

        virtual void Process(Operation tyoe_operation) = 0;
};


class MTF : public StreamProcessor{
    private:
        char symbolTable[26];

    public:
        void fillSymbolTable(){
            for( int x = 0; x < 26; x++ )
	        symbolTable[x] = x + 'a';
        }

        void moveToFront( int i ){
            char t = symbolTable[i];
            for( int z = i - 1; z >= 0; z-- )
                symbolTable[z + 1] = symbolTable[z];
            symbolTable[0] = t;
        }

        std::string encode( std::string str ){
            fillSymbolTable();
            std::vector<int> output;
            for(std::string::iterator it = str.begin(); it != str.end(); it++ )
            {
                for( int i = 0; i < 26; i++ )
                {
                if( *it == symbolTable[i] )
                {
                    output.push_back( i );
                    moveToFront( i );
                    break;
                }
                }
            }
            std::string r;
            for(std::vector<int>::iterator it = output.begin(); it != output.end(); it++ )
            {
                std::ostringstream ss;
                ss << *it;
                r += ss.str() + " ";
            }
            return r;
        }  

        std::string decode(std::string str ){
            fillSymbolTable();
            std::istringstream iss( str ); 
            std::vector<int> output;
            std::copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(),std::back_inserter<std::vector<int> >(output));
            std::string r;
            for(std::vector<int>::iterator it = output.begin(); it != output.end(); it++ )
            {
                r.append( 1, symbolTable[*it] );
                moveToFront( *it );
            }
            return r;
        }


        MTF(std::istream& _i_stream , std::ostream& _o_stream) : StreamProcessor(_i_stream , _o_stream) {}
        MTF()  : StreamProcessor() {}

        void Process(Operation type_operation){
            std::string res;
            if (type_operation == Operation::encoding){
                std::string input ;
                get_istream() >> input;
                res = encode(input);
                get_ostream() << res;
            }
            if (type_operation == Operation::decoding){
                std::string input;
                std::getline(get_istream() , input);
                res = decode(input);
                get_ostream() << res;
            }
        }

};
