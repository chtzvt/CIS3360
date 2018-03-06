
int recta[26][26];

// procedurally generates caesar cipher shifts to
// populate the vigenere table
void generate_table() {
    for(int ROW = 0; ROW < 26; ROW++)
      for(int i = 1; i < 27; i++)
        recta[ROW][i] = (char)(96 + (i + (ROW+1)%26)); // the row >>is<< the shift!
}

char encipher_char(char msgchar, char keychar){
  int key_idx = (int)(keychar) - 96;
  int msg_idx = (int)(msgchar) - 96;
  return recta[key_idx][msg_idx];
}
