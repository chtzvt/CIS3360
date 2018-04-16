/*
 * CIS3360 - Spring 2018
 * Security in Computing - Assignment 2
 * Submitted by: Charlton Trezevant and Alexander Cote
 */

import java.util.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class ChecksumTester {
  
  private static class ChecksumCalculator {
    public static final int MASK_8_BIT = 0xFF;
    public static final int MASK_16_BIT = 0xFFFF;
    public static final int MASK_32_BIT = 0xFFFFFFFF;
    
    public ChecksumCalculator(){
      super();
    }

    public int fromString(String input, int mask){
      return this.fromBytes(input.getBytes(), mask);
    }
    
    public static int fromBytes(byte[] input, int mask){
      int sum = 0;
      int chunk_sz;
      
      switch(mask){
        case MASK_16_BIT:
          chunk_sz = 2;
          break;
          
        case MASK_32_BIT:
          chunk_sz = 4;
          break;
          
        default: // assumes MASK_8_BIT
          chunk_sz = 1;
      }
      
      for(int chunk = 0; chunk < input.length; chunk += chunk_sz){
        
        byte[] byte_chunk = new byte[chunk_sz];
        int chunk_sum = 0;
        
        for(int i = 0; i < chunk_sz; i++){
          byte_chunk[i] = input[chunk + i];
        }
        
        for(byte b : byte_chunk){
          //System.out.printf("%nChunk: %d %nChunk Size: %d%n Current: [%d]%n",chunk,chunk_sz,b);
          chunk_sum += b & 0xff;
        }
        
        sum += (chunk_sum);
        
      }
      
      return sum & mask;
    }
  }
  
  public static void main(String[] args){
    
    String testString = "AAAAAAAAAA" + System.lineSeparator();
    String testString_16 = "AAAAAAAAAA" + System.lineSeparator() + 'X';
    ChecksumCalculator checksum = new ChecksumCalculator();
    
    int sum_8 = checksum.fromString(testString, checksum.MASK_8_BIT);
    System.out.printf("Sum 8: %s%n", Integer.toHexString(sum_8));
    int sum_16 = checksum.fromString(testString_16, checksum.MASK_16_BIT);

    System.out.printf("Sum 16: %s%n", Integer.toHexString(sum_16));

  }
  
}
