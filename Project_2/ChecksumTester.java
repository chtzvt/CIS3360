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
      
      int num_chunks = input.length / chunk_sz;
      byte[][] chunks = new byte[num_chunks][chunk_sz];

      for(int i = 0; i < input.length; i += chunk_sz)
        for(int j = 0; j < chunk_sz; j++)
          chunks[i / num_chunks][j] = input[chunk + j];
      
      for(int i = 0; i < chunks.length; i++){
        
      }
      
        
      for(byte b : byte_chunk) // replace this with logic for packing chunks

          
        
        
      // Don't just add to the sum, add the sum of 2 chunks together to the overall checksum
      
      return sum & mask;
    }
  
    private int packChunk8(byte[] chunk){
      return chunk[0] & MASK_8_BIT;
    }
  
    private short packChunk16(byte[] chunk){
      return (short) ((chunk[0] << 8) | (chunk[2] & MASK_8_BIT));
    }
    
    private long packChunk32(byte[] chunk){
      return ((chunk[0] << 24) | (chunk[1] << 16) | (chunk[2] << 8) | chunk[3]) & MASK_32_BIT;
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
