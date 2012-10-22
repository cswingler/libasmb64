//
// b64.c
// --
// http://monobeard.github.com/
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int b64decode(char *in_str, char *out_str);

int b64decode_c(char *in_str, char *out_str)
{
  long buf = 0;
  short bits = 0;
  char *b64table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  char *p;
  unsigned int count = 0;
  unsigned char c;

  while (c = *in_str++)
  {
    p = b64table;

    while (*p)
      if (*p++ == c && *p--)
        break;

    if (p == b64table+64)
      continue;

    buf = (buf << 6) | (p - b64table);
    bits += 6;

    if (bits >= 8)
    {
      bits -= 8;
      *out_str++ = (unsigned char)(buf >> bits);
      count++;
    }
  }

  return count;
}

int main(int argc, char *argv[])
{
  char *in_str = "TG9yZW0gaXBzdW0gZG9sb3Igc2l0IGFtZXQsIGNvbnNlY3RldHVyIGFkaXBpc2Npb"
                 "mcgZWxpdC4gVXQgZWxlbWVudHVtLCBwdXJ1cyB2ZWwgZ3JhdmlkYSBwcmV0aXVtLC"
                 "BpcHN1bSBuaXNsIGZlcm1lbnR1bSB1cm5hLCBzZW1wZXIgZGlnbmlzc2ltIG5pc2w"
                 "gbWFnbmEgaW4gYXVndWUuIE1vcmJpIHVybmEgbnVuYywgZXVpc21vZCBub24gdWx0"
                 "cmljZXMgc3VzY2lwaXQsIG1hbGVzdWFkYSB1bGxhbWNvcnBlciBtYWduYS4gU2VkI"
                 "HRyaXN0aXF1ZSwgbWkgdmVsIHRpbmNpZHVudCBtYWxlc3VhZGEsIHZlbGl0IGxlby"
                 "BmZXJtZW50dW0gZHVpLCBsYWNpbmlhIGRhcGlidXMgZXN0IGVyb3MgZXUgZHVpLiB"
                 "QcmFlc2VudCBpbiBwdXJ1cyBkaWFtLCBpZCBldWlzbW9kIG1ldHVzLiBTZWQgdmVo"
                 "aWN1bGEgdGVsbHVzIGEgbmlzaSBmZXJtZW50dW0gZWdldCBwb3J0YSBsYWN1cyB0a"
                 "W5jaWR1bnQuIFV0IGFkaXBpc2NpbmcgbmlzbCBhIHZlbGl0IGN1cnN1cyBhbGlxdW"
                 "V0LiBTZWQgc29kYWxlcyBtZXR1cyBlZ2V0IGxlbyBwaGFyZXRyYSBxdWlzIGVsZW1"
                 "lbnR1bSB1cm5hIGZyaW5naWxsYS4gSW4gbWV0dXMgcHVydXMsIHNvZGFsZXMgYWMg"
                 "c29sbGljaXR1ZGluIG5vbiwgcHVsdmluYXIgaWQgbGFjdXMuIFByYWVzZW50IGNvb"
                 "nNlY3RldHVyIHRlbXBvciBzYXBpZW4gYWMgYWxpcXVhbS4gQWxpcXVhbSBldSBmZW"
                 "xpcyBhIGVsaXQgdHJpc3RpcXVlIHJob25jdXMuIFN1c3BlbmRpc3NlIHBvdGVudGk"
                 "uIERvbmVjIHJob25jdXMgbWF1cmlzIGF0IGxlbyBjb25zZXF1YXQgY29tbW9kby4g"
                 "SW50ZWdlciBsaWd1bGEgdmVsaXQsIGNvbW1vZG8gYXQgcHVsdmluYXIgYWMsIHBlb"
                 "GxlbnRlc3F1ZSBwb3J0dGl0b3IgZXN0LiBRdWlzcXVlIGVnZXQgbWFzc2EgYSBtaS"
                 "BpbXBlcmRpZXQgY3Vyc3VzLiBOYW0gYW50ZSBhcmN1LCBjb252YWxsaXMgY29uZGl"
                 "tZW50dW0gc29kYWxlcyBldCwgY29uZGltZW50dW0gc2l0IGFtZXQgbWV0dXMuIER1"
                 "aXMgdHJpc3RpcXVlIGdyYXZpZGEgZmFjaWxpc2lzLg==";

  char *out_str1 = NULL;
  char *out_str2 = NULL;
  int MALLOC_SZ = ((strlen(in_str)/4)*3)+1;

  out_str1 = (char *)malloc(MALLOC_SZ);
  memset(out_str1, 0, MALLOC_SZ);

  out_str2 = (char *)malloc(MALLOC_SZ);
  memset(out_str2, 0, MALLOC_SZ);

  printf("(%d)   b64decode = %s\n", b64decode(in_str, out_str1), out_str1);
  printf("(%d) b64decode_c = %s\n", b64decode_c(in_str, out_str2), out_str2);

  return 0;
}

