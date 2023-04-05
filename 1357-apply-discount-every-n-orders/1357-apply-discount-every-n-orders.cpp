int arr[201];
int dis;
int N;
int D=0;
class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
            N=n;
            D=0;
        for(int i=0;i<products.size();i++){
                arr[products[i]]=prices[i];
        }
            dis=discount;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        long double res=0,hun=100,cp=100;
            D++;
            if(D==N){
                    cp-=dis;
                    D=0;
            }
            int n=product.size();
            for(int i=0;i<n;i++){
                    res+=amount[i]*arr[product[i]];
            }
            res*=cp;
            res/=hun;
            return res;
            
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */