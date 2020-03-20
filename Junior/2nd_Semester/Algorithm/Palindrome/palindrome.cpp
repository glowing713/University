#include <iostream>
#include <fstream>

using namespace std;

long isPalindrome(string str){
    long cnt = 0, begin = 0, end = 0;
    long length = str.size();
    
    if(length > 1000 || length < 1){
        return -1;
    }
    
    for(begin = 0, end = length - 1; end >= 0 , begin < end; ++begin, --end){
        // 양쪽 글자가 다르면 발동
        if(str[begin] != str[end]){
            
            if(begin == end - 1){
                if((cnt + 1) > 2){
                    return -1;
                }else
                    return cnt + 1;
            }
            
            if(str[begin] == str[end - 1]){
                if(str[begin + 1] == str[end]){
                    if(str[begin + 1] == str[end - 2]){
                        end -= 1;
                        ++cnt;
                    }else if(str[begin + 2] == str[end - 1]){
                        begin += 1;
                        ++cnt;
                    }
                }else{
                    end -= 1;
                    ++cnt;
                }
            }else if(str[begin + 1] == str[end]){
                begin += 1;
                ++cnt;
            }else if(str[begin] == str[end - 2]){
                end -= 2;
                cnt += 2;
            }else if(str[begin + 2] == str[end]){
                begin += 2;
                cnt += 2;
            }else{
                return -1;
            }
        }
        if(cnt > 2){
            return -1;  // 추가해야할 글자가 3이상인 경우로 조건에 따른 펠린드롬이 될수없다.
        }
    }
    return cnt;
}


int main(void){
    ifstream ifs;
    ofstream ofs;
    ifs.open("palindrome.inp");
    ofs.open("palindrome.out");
    
    int cycle = 0;
    string str = " ";
    
    
    ifs >> cycle;
    
    for(int i = 0; i < cycle; ++i){
        ifs >> str;
        
        ofs << isPalindrome(str) << endl;
    }
    
    
    ifs.close();
    ofs.close();
    
    return 0;
}
