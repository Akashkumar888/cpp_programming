
class Solution {
  public:
    bool wifiRange(string &s, int x) {

        int n=s.size();

        int wifi=0;
        int room=0;

        // move wifi pointer to first router
        while(wifi<n && s[wifi]!='1'){
            wifi++;
        }

        while(room<n){

            // no wifi left
            if(wifi>=n){
                return false;
            }

            // room covered
            if(abs(room-wifi)<=x){
                room++;
            }
            else if(room<wifi-x){
                // uncovered room before wifi range
                return false;
            }
            else{
                // move to next wifi
                wifi++;

                while(wifi<n && s[wifi]!='1'){
                    wifi++;
                }
            }
        }

        return true;
    }
};


class Solution {
  public:
    bool wifiRange(string &s, int x) {

        int n=s.size();

        int wifi=0;

        while(wifi<n && s[wifi]!='1'){
            wifi++;
        }

        for(int room=0;room<n;room++){

            while(wifi<n && room>wifi+x){

                wifi++;

                while(wifi<n && s[wifi]!='1'){
                    wifi++;
                }
            }

            if(wifi>=n || abs(room-wifi)>x){
                return false;
            }
        }

        return true;
    }
};

