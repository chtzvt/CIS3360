/*
	CIS3360 - Project 1
	Michael McAlpin
	By Charlton Trezevant and Alexander Cote
*/

/*

  The Vignere class implements a classical Vignere cipher, which
  operates with a block size of 512 characters.
  
  Usage:
      java Vignere path/to/plain.txt path/to/key.txt

*/

import java.util.*;
import java.io.*;

public class Vigenere {
  
  private static class VigenereCipher {
    
    private VigenereCipher(){
      super();
    }
    
    private static char encipherCharacter(char message_char, char key_char){
      return (char)(((int)(message_char) + (int)(key_char) - 194)%26 + 97);
    }
  
    public static String encipher(String plaintext, String key){
      String ciphertext = "";
      
      for(int i = 0; i < plaintext.length(); i++)
        ciphertext += encipherCharacter(plaintext.charAt(i), key.charAt((i % key.length())));
        
      return ciphertext;
    }
  }
  
  // Generic superclass for static data manipulation helper classes
  private static class DataHandler {
    
    // manages retrieval of source texts from the filesystem
    public static class FileHandler {
      private FileHandler(){
        super();
      }
      
      private static String readFile(String filename){
          
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
      
      // Wraps several helper methods - retrieves cleaned source text from a file
      public static String loadCleanFile(String filename){
        String contents = DataHandler.InputFormatter.clean(DataHandler.FileHandler.readFile(filename));
        return contents;
      }
      
    }
    
    // Cleans/pads/formats input files
    public static class InputFormatter {
      private InputFormatter(){
        super();
      }
      
      public static String clean(String input){
        return input.replaceAll("[^A-Za-z0-9]", "").toLowerCase();
      }
      
      public static String addPadding(String plaintext, String key){
        int padAmount = ((2 * key.length()) - plaintext.length());

        for(int i = 0; i < padAmount; i++)
          plaintext += 'x';
        
        return plaintext;
      }
      
    }
    
    // handles program output display (80 column block formatting, etc)
    public static class OutputFormatter {
      private static int OUTPUT_LINE_LENGTH = 80;
      
      private OutputFormatter(){
        super();
      }
      
      public static void printBlockOutput(String input){
        int i = 0;
        int j = 0;
        
        while(j < input.length()){
          String fmt = "%c";
          
          if(i == (OUTPUT_LINE_LENGTH - 1)){
            fmt += "%n";
            i = 0;
          } else {
            i++;
          }
            
          System.out.printf(fmt, input.charAt(j));
          j++;
        }
      }
    }
    
    private DataHandler(){
      super();
    }
    
  }
  
  public static void main(String[] args){
        
    String key = DataHandler.FileHandler.loadCleanFile(args[1]);
    
    System.out.printf("%n%nVigenere Key:%n%n");
    DataHandler.OutputFormatter.printBlockOutput(key);
    
    String plaintext = DataHandler.FileHandler.loadCleanFile(args[0]);
    plaintext = DataHandler.InputFormatter.addPadding(plaintext, key);
    
    System.out.printf("%n%n%nPlaintext:%n%n");
    DataHandler.OutputFormatter.printBlockOutput(plaintext);
    
    String ciphertext = VigenereCipher.encipher(plaintext, key);
    
    System.out.printf("%n%n%nCiphertext:%n%n");
    DataHandler.OutputFormatter.printBlockOutput(ciphertext);
    
    System.out.printf("%n");
  }
  
}
