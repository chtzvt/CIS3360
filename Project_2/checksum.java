/*
 * CIS3360 - Spring 2018
 * Security in Computing - Assignment 2
 * Submitted by: Charlton Trezevant and Alexander Cote
 */

import java.util.*;
import java.io.*;

public class checksum {
  
  private static class ChecksumCalculator {
    
    private ChecksumCalculator(){
      super();
    }
    
    private sum8Bit(String input){
      
    }

    private sum16Bit(String input){
      
    }

    private sum32Bit(String input){
      
    }
    
  }
  
  // Generic superclass for static data manipulation helper classes
  private static class DataHandler {
    private static int MAX_BLOCK_SIZE = 512;
    
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
        String contents = DataHandler.FileHandler.readFile(filename);
        return (contents.length() >= MAX_BLOCK_SIZE) ? contents.substring(0, MAX_BLOCK_SIZE) : contents;
      }
      
    }
    
    // Cleans/pads/formats input files
    public static class InputFormatter {
      private InputFormatter(){
        super();
      }
      
      public static String addPadding(String plaintext, String key){
        // Compute the total number of times the key fits into the plaintext, rounding up
        int key_padding = (plaintext.length() / key.length()) + ((plaintext.length() % key.length() == 0) ? 0 : 1);
        // Padding amount = amount to pad plaintext to fit the key into it evenly
        int padAmount = (key_padding * key.length()) - plaintext.length();
        
        if(plaintext.length() >= MAX_BLOCK_SIZE)
          padAmount = 0;
        
        // Enforce 512 character block size for padded plaintext
        if(plaintext.length() + padAmount > MAX_BLOCK_SIZE)
          padAmount = MAX_BLOCK_SIZE - plaintext.length();

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
        
    String text = DataHandler.FileHandler.loadCleanFile(args[0]);
    

    
    System.out.printf("%n");
  }
  
}
