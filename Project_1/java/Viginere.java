import java.util.*;
import java.io.*;

public class Viginere {
  private String plaintext, ciphertext, key;
  
  private static class ViginereCipher {
    
    public ViginereCipher(){
      super();
    }
    
    public static char encipherCharacter(char message_char, char key_char){
      return (char)(((int)(message_char) + (int)(key_char) - 194)%26 + 97);
    }
  
    public static String encipher(String plaintext, String key){
      String ciphertext = "";
      
      for(int i = 0; i < plaintext.length(); i++)
        ciphertext += encipherCharacter(plaintext.charAt(i), key.charAt(i));
        
      return ciphertext;
    }
  }
  
  private static class DataHandler {
    private static int MAX_STRING_LENGTH = 512;
    private static int OUTPUT_LINE_LENGTH = 80;
    
    // manages retrieval of source texts from the filesystem
    public static class FileHandler {
      public FileHandler(){
        super();
      }
      
      public static String readFile(String filename){
        
        String file_line = "";
        String file_contents = "";
        
        try {
          FileReader reader = new FileReader(filename);
          BufferedReader buffer = new BufferedReader(reader);
          
          while((file_line = buffer.readLine()) != null) {
            file_contents += file_line;
          }
          
          buffer.close();
        }
        
        catch(IOException e) {
          System.out.printf("*** An error was encountered while loading the file: ***%n");
          e.printStackTrace();
        }

        return file_contents;
        
      }
      
    }
    
    // Cleans/pads/formats input files
    public static class InputFormatter {
      public InputFormatter(){
        super();
      }
      
      public static String clean(String input){
        return input.replaceAll("[^A-Za-z0-9]", "").toLowerCase();
      }
      
      public static String addPadding(String input){
        int padAmount = ((MAX_STRING_LENGTH - input.length()) > 0) ? (MAX_STRING_LENGTH - input.length()) : 0;
        
        for(int i = 0; i < padAmount; i++)
          input += 'x';
        
        return input;
      }
      
    }
    
    // handles program output display (formatting, etcetera)
    public static class OutputFormatter {
      public OutputFormatter(){
        super();
      }
      
      public static void printBlockOutput(String input){
        int i = 0;
        int j = 0;
        
        while(j < input.length()){
          String fmt = "%c";
          
          if(i == 80){
            fmt += "%n";
            i = 0;
          }
            
          System.out.printf(fmt, input.charAt(j));
          i++;
          j++;
        }
      }
    }
    
    public DataHandler(){
      super();
    }
    
    public static String loadKey(String filename){
      String key = InputFormatter.clean(FileHandler.readFile(filename));
      MAX_STRING_LENGTH = (key.length() >= 512) ? 512 : key.length();
      return key;
    }
    
    public static String loadPlaintext(String filename){
      String plaintext = InputFormatter.clean(FileHandler.readFile(filename));
      return InputFormatter.addPadding(plaintext);
    }
    
  }
  
  public static void main(String[] args){
    
    DataHandler datahandler = new DataHandler();
    
    String key = DataHandler.loadKey(args[1]);
    
    System.out.printf("%n%nKey: %n");
    DataHandler.OutputFormatter.printBlockOutput(key);
    
    String plaintext  = DataHandler.loadPlaintext(args[0]);
    
    System.out.printf("%n%nPlaintext: %n");
    DataHandler.OutputFormatter.printBlockOutput(plaintext);
    
    String ciphertext = ViginereCipher.encipher(plaintext, key);
    
    System.out.printf("%n%nCiphertext: %n");
    DataHandler.OutputFormatter.printBlockOutput(ciphertext);
    
  }
  
}
