#include <iostream>
#include <string>

int str_to_int(char number){
    
    switch (number){
        case '0':
            return 0;
            break;
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
        case '9':
            return 9;
            break;
        default:
            throw std::invalid_argument("invalid");
            break;
    }
}

int main(){
    std::cout<<"Validating Credit Cards with Luhn's Check Algorithm"<< std::endl;
    bool pass = false;
    std::string credit_numbers;

    while(pass==false){
        std::cout<<"Please enter Numbers with no space or special characters"<< std::endl;
        std::cin>> credit_numbers;
        if (credit_numbers.length()==16)
        {
            pass=true;
        }else{
            std::cout<<"Seems there was an error in your input please try again"<<std::endl;
        }
    }
    int odd_side = 0;

    for (int i = 1; i < credit_numbers.length(); i+=2)
    {
        int a =0;
        a = str_to_int(char(credit_numbers[i]));
        odd_side+=a;
    }
    

    

    int even_side =0;

    for(int i = 0; i < credit_numbers.length(); i+=2)
    {
        int b=0;
        b = str_to_int(char(credit_numbers[i]));
        b*=2;
        if (b>=10)
        {
            std::string temp ="";
            temp = std::to_string(b);
            for (int g = 0; g < 2; g++)
            {
                int c=0;
                c= str_to_int(char(temp[g]));
                even_side+=c;
            }
            
        }else{
         even_side+=b;
        }
        
    }

    int final_result= even_side + odd_side;

    if(final_result %10 ==0){
        std::cout<<"Credit Card Valid"<< std::endl;
    }else{
        std::cout<<"Credit Card Not Valid"<<std::endl;
    }

}

