#include <android/log.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <jni.h>
#include "util.h"

#define __S_A 30
//#$%*&^2323124(*&
static const char CRYPTO_KEY[17] = {__S_A + 5, __S_A + 6, __S_A + 7, __S_A + 12, __S_A + 8, __S_A + 64, __S_A + 20, __S_A + 21, __S_A + 20, __S_A + 21, __S_A + 19, __S_A + 20, __S_A + 22, __S_A + 10, __S_A + 12, __S_A + 8, __S_A - 30};

JNIEXPORT jstring JNICALL Java_com_statistics_channel_Crypto_native_1encode (JNIEnv *env, jobject clazz, jstring text, jstring key)
{
    if ( text == NULL ) {
        LOGE( "[-] native_encode : text is null" );
        return(NULL);
    }

    if ( text == NULL ) {
        return(NULL);
    }
    const char	*cStr		= (*env)->GetStringUTFChars( env, text, NULL );
    const char	*cKey		= (*env)->GetStringUTFChars( env, key, NULL );
    char		*result		= encode( (char *) cStr, (char *) cKey );
    jstring		javaResult	= (*env)->NewStringUTF( env, result );
    free( result );
    return(javaResult);
}


JNIEXPORT jstring JNICALL Java_com_statistics_channel_Crypto_native_1decode (JNIEnv *env, jobject clazz, jstring text, jstring key)
{
    if ( text == NULL ) {
        LOGE( "[-] native_encode : text is null" );
        return(NULL);
    }

    if ( text == NULL ) {
        return(NULL);
    }

    const char	*cStr		= (*env)->GetStringUTFChars( env, text, NULL );
    const char	*cKey		= (*env)->GetStringUTFChars( env, key, NULL );
    char		*result		= decode( (char *) cStr, (char *) cKey );
    if(result == NULL) {
        return NULL;
    }
    jstring		javaResult	= (*env)->NewStringUTF( env, result );
    free( result );
    return(javaResult);
}


char *encode( const char * data, const char *key )
{
    size_t	len		= 0;
    char	* encrypt_data	= xxtea_encrypt( data, strlen( data ), key, &len );
    if(encrypt_data == NULL)
        return NULL;
    char * base64_data = (char *) base64_encode( encrypt_data, len );
    if(base64_data == NULL)
        return NULL;
    free( encrypt_data );
    return(base64_data);
}


char * decode( const char *data, const char *key )
{
    size_t	len;
    char	* base64_data	= (char *) base64_decode( data, &len );
    if(base64_data == NULL)
        return NULL;
    char	* decrypt_data	= xxtea_decrypt( base64_data, len, key, &len );
    free( base64_data );
    if(base64_data == NULL)
        return NULL;
    return(decrypt_data);
}