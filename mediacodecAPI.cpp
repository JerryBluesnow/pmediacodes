#include "com_fusion_serv_utils_mediacodec.h"
#include <stdio.h>
#include <ostream>

using namespace std;

#ifdef _WIN32
#define  EXPORT_API extern "C" __declspec(dllexport)
#else
#define  EXPORT_API extern "C"  __attribute__ ((visibility("default")))
#endif

typedef short  Word16;

extern "C" void G729aInitDecoder();
extern "C" void G729aDecoder(unsigned char* bitstream, Word16* synth_short, int bfi);
extern "C" unsigned char linear2alaw(short	pcm_val);

/*
 * Class:     com_fusion_serv_utils_mediacodec
 * Method:    G729aInitEncoder
 * Signature: ()V
 */
extern "C" JNIEXPORT void JNICALL Java_com_fusion_serv_utils_mediacodec_G729aInitEncoder
  (JNIEnv *, jobject);

/*
 * Class:     com_fusion_serv_utils_mediacodec
 * Method:    G729aInitDecoder
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_fusion_serv_utils_mediacodec_G729aInitDecoder
(JNIEnv*, jobject)
{
	G729aInitDecoder();
}

/*
 * Class:     com_fusion_serv_utils_mediacodec
 * Method:    g729aencoder
 * Signature: ([S)[B
 */
extern "C" JNIEXPORT jbyteArray JNICALL Java_com_fusion_serv_utils_mediacodec_g729aencoder
  (JNIEnv *, jobject, jshortArray);

/*
 * Class:     com_fusion_serv_utils_mediacodec
 * Method:    g729adecoder
 * Signature: ([BI)[S
 */
JNIEXPORT jshortArray JNICALL Java_com_fusion_serv_utils_mediacodec_g729adecoder
(JNIEnv* env, jobject obj, jbyteArray bitstream, jint bfi)
{
	unsigned char g729data[100 * 8] = { 0 };
	short linear[800 * 8] = { 0 };

	jbyte* bitstreamdata = env->GetByteArrayElements(bitstream, NULL);

	jsize elements_cnt = 0;
	jsize size = env->GetArrayLength(bitstream);
	for (int step = 0; step < size / 10; step++)
	{
		for (int i = 0; i < 10; i++) {
			g729data[step * 10 + i] = (unsigned char)bitstreamdata[step * 10 + i];
		}
		G729aDecoder(&g729data[step * 10], &linear[step * 80], 0);
		elements_cnt += 80;
	}

	env->ReleaseByteArrayElements(bitstream, bitstreamdata,0);

	jshortArray shortArr = env->NewShortArray(size * 8);
	jshort* pshort = new jshort[elements_cnt];

	for (int i = 0; i < elements_cnt; i++) {
		pshort[i] = linear[i];
	}

	env->SetShortArrayRegion(shortArr, 0, elements_cnt, pshort);

	delete[]pshort;
	return shortArr;
}

/*
 * Class:     com_fusion_serv_utils_mediacodec
 * Method:    g729aPCInitEncoder
 * Signature: ()V
 */
extern "C" JNIEXPORT void JNICALL Java_com_fusion_serv_utils_mediacodec_g729aPCInitEncoder
  (JNIEnv *, jobject);

/*
 * Class:     com_fusion_serv_utils_mediacodec
 * Method:    g729aPCInitDecoder
 * Signature: ()V
 */
extern "C" JNIEXPORT void JNICALL Java_com_fusion_serv_utils_mediacodec_g729aPCInitDecoder
  (JNIEnv *, jobject);

/*
 * Class:     com_fusion_serv_utils_mediacodec
 * Method:    g729aPCencoder
 * Signature: ([S)[B
 */
extern "C" JNIEXPORT jbyteArray JNICALL Java_com_fusion_serv_utils_mediacodec_g729aPCencoder
  (JNIEnv *, jobject, jshortArray);

/*
 * Class:     com_fusion_serv_utils_mediacodec
 * Method:    g729aPCdecoder
 * Signature: ([BI)[S
 */
extern "C" JNIEXPORT jshortArray JNICALL Java_com_fusion_serv_utils_mediacodec_g729aPCdecoder
  (JNIEnv *, jobject, jbyteArray, jint);

/*
 * Class:     com_fusion_serv_utils_mediacodec
 * Method:    g711alawencoder
 * Signature: ([S)[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_fusion_serv_utils_mediacodec_g711alawencoder
(JNIEnv* env, jobject obj, jshortArray bitstream)
{
	short lineardata[800 * 8] = { 0 };
	unsigned char alaw[800 * 8] = { 0 };

	jshort* bitstreamdata = env->GetShortArrayElements(bitstream, NULL);

	jsize size = env->GetArrayLength(bitstream);
	jsize elements_cnt = size;
	for (int step = 0; step < size; step++)
	{
        alaw[step] = linear2alaw(bitstreamdata[step]);
	}

	env->ReleaseShortArrayElements(bitstream, bitstreamdata,0);

	jbyteArray byteArr = env->NewByteArray(size);
	jbyte* pbyte = new jbyte[elements_cnt];

	for (int i = 0; i < elements_cnt; i++) {
		pbyte[i] = alaw[i];
	}

	env->SetByteArrayRegion(byteArr, 0, elements_cnt, pbyte);

	delete[]pbyte;
	return byteArr;
}
/*
 * Class:     com_fusion_serv_utils_mediacodec
 * Method:    g711alawdecoder
 * Signature: ([B)[S
 */
extern "C" JNIEXPORT jshortArray JNICALL Java_com_fusion_serv_utils_mediacodec_g711alawdecoder
  (JNIEnv *, jobject, jbyteArray);


/*
C:\Users\JerryZhang\source\repos\G729decoder\inc;D:\Program Files\Java\jdk1.8.0_162\include\win32;D:\Program Files\Java\jdk1.8.0_162\include;$(IncludePath)
*/