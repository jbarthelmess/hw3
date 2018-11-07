#include<iostream>
#include<cmath>

typedef unsigned int u_int;

u_int exp_mod(u_int base, u_int exp, u_int mod)
{
    long unsigned int sol = base;
    long unsigned int cur_exp = exp;
    while(cur_exp > 1)
    {
        if(cur_exp %2 == 0)
        {
            sol = (sol*sol) % mod;
            cur_exp = cur_exp/2;
        }
        else
        {
            u_int ender = exp_mod(sol, cur_exp-1, mod);
            return sol*ender % mod;
        }
    }
    return sol;
}

int main() {
    int a, b, p, q, n, x_0, k, h, m;
    a = -57;
    b = 52;
    p = 499;
    q = 547;
    n = p*q;
    x_0  = 159201;
    m = 639244;
    
    k = (int) log2(n);
    h = (int) log2(k);
    
    long holder = x_0;
    long changeable;
    int chunk = 0;
    int nibble = 0;
    int aholder;
    int bholder;
    
    int encrypt = 0;
    int count = 0;
    //std::cout << "h: " << h << std::endl;
    while(m > 0) {
        nibble = 0;
        chunk = 0;
        for(int i = 0; i < h; i++) {
            aholder = m %2;
            chunk += (aholder << i);
            m = m >> 1;
            //std::cout << "bit: " << aholder << "\nchunk: " << chunk << std::endl;
        }
        //std::cout << std::endl;
        holder = (holder*holder) % n;
        changeable = holder;
        //std::cout << changeable << std::endl;
        for(int i = 0; i < h; i++) {
            bholder = changeable %2;
            nibble += (bholder << i);
            changeable = changeable >> 1;
            //std::cout << "bit: " << bholder << "\nnibble: " << nibble << std::endl;
        }
        /*std::cout << std::endl;
        std::cout << "nibble: " << nibble << "\nchunk: " << chunk << std::endl;
        std::cout << std::endl;
        std::cout << "4-bit encryption: " << (nibble^chunk) << std::endl;
        */
        encrypt += ((nibble ^ chunk) << (h*count));
        count++;
    }
    
    count++;
    holder = (holder*holder) % n;
    
    std::cout << "Encrypt text: " << encrypt << "\nX_(t+1): " << holder << "\n(t+1):" << count << std::endl;
    
    //DECRYPTION
    
    int d1, d2, u, v;
    d1 = exp_mod((p+1)/4, count, p-1);
    d2 = exp_mod((q+1)/4, count, q-1);
    //std::cout << d1 << " " << d2 << std::endl;
    u = exp_mod(holder, d1, p);
    v = exp_mod(holder, d2, q);
    //std::cout << u << " " << v << std::endl;
    
    long decrypt_start = (u*b*q + v*a*p) % n;
    if(decrypt_start < 0) {
        decrypt_start += n;
    }
    //std::cout << decrypt_start << std::endl;
    
    int decrypt=0;
    
    for(int i = 0; i < count; i++) {
        nibble = 0;
        chunk = 0;
        for(int j = 0; j < h; j++) {
            aholder = encrypt %2;
            chunk += (aholder << j);
            encrypt = encrypt >> 1;
        }
        decrypt_start = (decrypt_start*decrypt_start) %n;
        changeable = decrypt_start;
        for(int j = 0; j < h; j++) {
            bholder = changeable %2;
            nibble += (bholder << j);
            changeable = changeable >> 1;
            //std::cout << "bit: " << bholder << "\nnibble: " << nibble << std::endl;
        }
        decrypt += ((nibble ^ chunk) << (h*i));
    }
    
    std::cout << "Decrypt text: " << decrypt << std::endl;
    
    return 0;
}
