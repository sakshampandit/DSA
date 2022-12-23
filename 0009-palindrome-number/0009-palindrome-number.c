

bool isPalindrome(int x){ 
   long long int rev=0,r=0,num=x;
        while(num>0)
        {
            r=num%10;
            rev=(rev*10)+r;
            num=num/10;
        }if(rev==x)
            return true;
    else 
        return false;

}