function encipher_char(msgchar, keychar){
  console.log("Code for msg " + msgchar + ": " + msgchar.charCodeAt());
  console.log("Code for key " + keychar + ": " + keychar.charCodeAt() + " (shift: " + ((keychar.charCodeAt() - 96)%26) + ")");
  console.log("Code for " + msgchar + " using " + keychar + ": " + (95 + ((msgchar.charCodeAt() - 96) + ((keychar.charCodeAt() - 96)%26))));
  return String.fromCharCode(((msgchar.charCodeAt() + keychar.charCodeAt() - 194) % 26) + 97);
}

function encipher(plaintext, key, msglen) {
  var ciphertext = [];
  ciphertext[msglen-1] = '\0';

  for(var i = 0; i < msglen; i++)
    ciphertext[i] = encipher_char(plaintext[i], key[i]);

  return ciphertext;
}

var str = "";
var plaintext = 'wikipediaisawebbasedfreecontentencyclopediaprojectsupportedbythewikimediafoundationandbasedonamodelofopenlyeditablecontentandisrankedthefifthmostpopularwebsitexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx';
var keytext = 'thisbigbadisaconnivingmalepoliticianhehastakenovertheuniversewithanewinventionhecommandsasmallteamofeliteunderlingsandcanonlybedefeatedthroughwitandstrategyhecommandsasmallteamofeliteunderlingsandcanonlybedefeatedthroughwitandstrategy';
enc = encipher(plaintext,keytext,plaintext.length);

for(var item of enc)
   str += "" + item;

// Output: ppsaqmjjalaswgponazlsxqenschpvmmpkypsswevbazvbxzgklbtjbzoiutcppxdixmimqdeshcbqhxkczmnqesswpoylfsdqztjzxxrflhhzeiorwcbqveahnybjwuesoewxkxmztnntkampbsmerrpihqpxgljjxkapxpjxiiqbxjlcbifqbrkaboifkdpxkazxklkivybabcbxqbaqeolrdetfqxkapqoxqbdv

console.log(str);
