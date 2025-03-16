
class Codec {
  public:
  
      // Encodes a list of strings to a single string.
      string encode(vector<string>& strs) {
          string res = "";
          for (string s : strs) {
              res += to_string(s.size()) + "#" + s;
          }
          return res;
      }
  
      // Decodes a single string to a list of strings.
      vector<string> decode(string s) {
          vector<string> res;
          int i = 0;
          while (i < s.size()) {
              int j = i;
              // Find '#'
              while (s[j] != '#') {
                  j++;
              }
              int length = stoi(s.substr(i, j - i));
              string str = s.substr(j + 1, length);
              res.push_back(str);
              i = j + 1 + length;
          }
          return res;
      }
  };
  