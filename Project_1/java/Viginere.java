import java.util.*;
import java.io.*;

public class Viginere {
  private String plaintext, ciphertext, key;
  
  private static class Cipher {
    
    public Cipher(){
      super();
    }
    
    public char encipherCharacter(char message_char, char key_char){
      return (char)(((int)(message_char) + (int)(key_char) - 194)%26 + 97);
    }
  
    public String encipher(String plaintext, String key){
      String ciphertext = "";
      
      for(int i = 0; i < plaintext.length(); i++)
        ciphertext += encipherCharacter(plaintext.charAt(i), key.charAt(i));
        
      return ciphertext;
    }
  }
  
  private static class DataHandler {
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
      
      public static String format(String input){
        return input.replaceAll("[^A-Za-z0-9]", "").toLowerCase();
      }
      
      public static String addPadding(String input){
        String fmt = "%-" + (512 - input.length()) + "s";
        return String.format("%s", input).replace(' ', 'x');
      }
    }
    
    // handles program output display (formatting, etcetera)
    public static class OutputFormatter {
      public OutputFormatter(){
        super();
      }
      
    }
    
    public DataHandler(){
      super();
    }
    
    public static String getKey(String filename){
      String key = FileHandler.readFile(filename);
      return InputFormatter.format(key);
    }
    
  }
  

  public static void main(String[] args){
    
    DataHandler datahandler = new DataHandler();
    
    String plaintext  = DataHandler.getPlaintext(args[0]);
    String key = DataHandler.getKey(args[0]);
    
  }
  
}
