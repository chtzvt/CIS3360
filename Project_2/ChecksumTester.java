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
      
      for(byte b : input){
        sum += (b & 0xff);
      }
      
      return sum & mask;
    }
  }
  
  public static void main(String[] args){
    
    String testString = "AAAAAAAAAA" + System.lineSeparator();
    String testString_16 = "AAAAAAAAAA" + System.lineSeparator() + 'X';
    ChecksumCalculator checksum = new ChecksumCalculator();
    
    int sum_8 = checksum.fromString(testString, checksum.MASK_8_BIT);
    int sum_16 = checksum.fromString(testString, checksum.MASK_16_BIT);

    System.out.printf("Sum 8: %s%nSum 16: %s%n", Integer.toHexString(sum_8), Integer.toHexString(sum_16));

  }
  
}
