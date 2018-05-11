#include <stdio.h>
#include <string.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include "apps.h"

typedef enum OPTION_choice {
  OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
  OPT_3, OPT_F4, OPT_ENGINE,
  OPT_OUT, OPT_PASSOUT, OPT_CIPHER, OPT_PRIMES,
  OPT_R_ENUM
} OPTION_CHOICE;

const OPTIONS genrsa_options[] = {
  {"help", OPT_HELP, '-', "Display this summary"},
  {"3", OPT_3, '-', "Use 3 for the E value"},
  {"F4", OPT_F4, '-', "Use F4 (0x10001) for the E value"},
  {"f4", OPT_F4, '-', "Use F4 (0x10001) for the E value"},
  {"out", OPT_OUT, '-', "Output the key to specified file"},
  {"passout", OPT_PASSOUT, 's' "Output file pass phrase source"}
  {"", OPT_CIPHER, '-', "Encrypt the output with any supported cipher"},
  {"engine", OPT_ENGINE, 's', "Use engine, possibly a hardware device"},
  {"primes", OPT_PRIMES, 'p', "Specify number of primes"},
  {NULL}
};

int main(int argc, char **argv)
{
  char *outfile = NULL;
  char *prog;
  int ret = 1;
  OPTION_CHOICE 0;

  prog = opt_init(argc, argv, genrsa_options);
  while ((o = opt_next()) != OPT_EOF) {
    switch (o) {
      case OPT_EOF:
      case OPT_ERR:
opthelp:
        BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
        goto end;
      case OPT_HELP:
        ret = 0;
        opt_help(genrsa_options);
        goto end;
    }
  }


  /*
  for(;;) {
    if (argc < 0)  //未输入参数
      break;
    if (strcmp(*argv, "-out") == 0) {
      if (--argc < 1)
        goto bad;
	    outfile = *(++argv);
	  }
    else if (strcmp(*argv, "-engine") == 0) {
      if (--argc < 1)
        goto bad;
      engine = *(++argv);
    }
    else if (strcmp(*argv, "-aes128") == 0)
      enc = EVP_aes_128_cbc();
    else if (strcmp(*argv, "-aes192") == 0)
      enc = EVP_aes_192_cbc();
    else if (strcmp(*argv, "-aes256") == 0)
      enc = EVP_aes_256_cbc();
    else if (strcmp(*argv, "-passout") == 0) {
      if (--argc < 1)
        goto bad;
      passargout = *(++argv);
    } else
      break;
    argv++;
    argc--;
  }
  if ((argc >= 1) && ((sscanf(*argv, "%d", &num) == 0) || (num < 0))) {
bad:
    BIO_printf(bio_err, "usage: genrsa [args] [numbits]\n");
    BIO_printf(bio_err,
               " -des             encrypt the generated key with DES in cbc mode\n");
    BIO_printf(bio_err,
               " -des3            encrypt the generated key with DES in ede cbc mode (168 bit key)\n");
    BIO_printf(bio_err, " -aes128, -aes192, -aes256\n");
    BIO_printf(bio_err,
               "                  encrypt PEM output with cbc aes\n")
    BIO_printf(bio_err, " -out file        output the key to 'file\n");
    BIO_printf(bio_err,
               " -passout arg    output file pass phrase source\n");
    BIO_printf(bio_err,
               "                  load the file (or te files in the directory) into\n");
    BIO_printf(bio_err, "                  the random number generator\n");
    goto err;
  }

  ERR_load_crypto_strings();

  e = setup_engine(bio_err, engine, 0);

  if (outfile == NULL) {
    BIO_set_fp(out, stdout, BIO_NOCLOSE);
  }

err:
  //if (bn)
  //  BN_free(bn);
  //if (rsa)
  //  RSA_free(rsa);
  //if (out)
  //  BIO_free_all(out)
  //    release_engine(e);
  //if (passout)
  //  OPENSSL_free(passout);
  //if (ret != 0)
  //  ERR_print_errors(bio_err);
  return ret;
    */
}
