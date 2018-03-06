// A beautiful, small vignere cipher implementation
// lovingly crafted by CHarlton Trezevant
// protip: https://xkcd.com/323/ is a very real thing :~)

// Note:
//    key_index = (int)(keychar) - 96);
//    msg_index = (int)(msgchar) - 96);
char encipher_char(char msgchar, char keychar){
  return (char)(97 + ( ((int)(msgchar) - 95) + ((int)(keychar) - 95)) % 26);
}

void encipher(char *plaintext, char *ciphertext, char *key, int msglen) {
  ciphertext[msglen-1] = '\0';
  for(int i = 0; i < msglen - 1; i++)
    ciphertext[i] = encipher_char(plaintext[i], key[i]);
}
