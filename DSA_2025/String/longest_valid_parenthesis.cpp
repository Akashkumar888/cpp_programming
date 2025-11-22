
int maxLength(string& s) {
  int n = s.size();
  int maxlen = 0, left = 0, right = 0;

  // Left to Right Scan
  for (int i = 0; i < n; i++) {
      if (s[i] == '(') left++;
      else right++;
      if (left == right) maxlen = max(maxlen, left * 2);
      else if (right > left) left = right = 0;
  }

  left = right = 0;

  // Right to Left Scan
  for (int i = n - 1; i >= 0; i--) {
      if (s[i] == ')') right++;
      else left++;
      if (left == right) maxlen = max(maxlen, 2 * right);
      else if (left > right) left = right = 0;
  }

  return maxlen;
}
