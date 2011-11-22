/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : rsaTester.cpp

* Purpose :

* Creation Date : 21-11-2011

* Last Modified : Tue 22 Nov 2011 07:08:09 PM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/
#include "rsaHandler.h"
#include <iostream>
#include <cstdlib>

using namespace std;
int main(int argc,char **argv)
{
  rsaHandler test_1;
  rsaHandler test_2;
  long data_l1,enc_data_l1;
  RSA *pub_key_1 = test_1.get_public_key();
  RSA *pub_key_2 = test_2.get_public_key();
  test_2.set_public_remote_key(pub_key_1);
  test_1.set_public_remote_key(pub_key_2);
  string enc_hi = test_1.encrypt_data((unsigned char *) "hello world");
  cout << enc_hi.size() << endl;
  enc_data_l1 = test_1.get_enc_data_length();
  data_l1 = test_1.get_orig_data_length();
  cout << test_2.decrypt_data((unsigned char *)enc_hi.c_str(),enc_data_l1,data_l1) << endl;
  return 0;
}
