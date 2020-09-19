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


JNIEXPORT void JNICALL Java_com_fusion_serv_utils_mediacodec_G729aInitDecoder
(JNIEnv*, jobject)
{
	G729aInitDecoder();
}

JNIEXPORT jshortArray JNICALL Java_com_fusion_serv_utils_mediacodec_g729decoder
(JNIEnv* env, jobject obj, jbyteArray bitstream, jint bfi)
{
	/* 最多支持 8*100 g729 转linear */
	/* 最少支持 10 g729 转linear */
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