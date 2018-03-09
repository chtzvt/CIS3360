// A beautiful, small vignere cipher implementation
// lovingly crafted by CHarlton Trezevant
// protip: https://xkcd.com/323/ is a very real thing :~)

// Note:
//    key_index = (int)(keychar) - 96);
//    msg_index = (int)(msgchar) - 96);
char encipher_char(char msgchar, char keychar){
  return (char)(((int)(msgchar) + (int)(keychar) - 194)%26 + 97);
}

//encipher(&plaintext, strlen(&plaintext), &keytext, strlen(&keytext), ciphertext);

void encipher(char *plaintext, int msglen, char *key, int keylen, char *ciphertext) {
  ciphertext[msglen] = '\0';
  for(int i = 0; i < msglen; i++)
    ciphertext[i] = encipher_char(plaintext[i], key[(i % keylen)]);
}
