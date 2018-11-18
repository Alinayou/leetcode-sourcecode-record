string addStrings(string num1, string num2)
{
    int i = num1.length()-1;
    int j = num2.length()-1;
    string res = "";
    int t1 = 0, t2 = 0; // t1 : 當下位數的值，t2 : 進位的值
    while(i >= 0 || j >= 0)
    {
        t1 = t2;
        if(i >= 0)
        {
            t1 += num1[i--] - '0';
        }
        if(j >= 0)
        {
            t1 += num2[j--] - '0';    
        }
        if(t1 > 9)
        {
            t2 = t1/10;
            t1 %= 10;
        }
        else
            t2 = 0;

        res.insert(res.begin(), t1 + '0');
    } 
    if(t2 > 0)
        res.insert(res.begin(), t2 + '0');
    return res;
}
