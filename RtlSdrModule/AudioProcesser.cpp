#include "AudioProcesser.h"

#define DEFAULT_BUF_LENGTH		(16 * 16384)
//static int do_exit = 0;
//static uint32_t iq_frames_to_read = 50000000;
static rtlsdr_dev_t *dev = NULL;
int writeWav = 0;
char *tempfilename = NULL;

#define DEFAULT_SAMPLE_RATE		2048000
#define DEFAULT_BANDWIDTH		0	/* automatic bandwidth */
#define MINIMAL_BUF_LENGTH		512
#define MAXIMAL_BUF_LENGTH		(256 * 16384)

uint64_t frequency = 100000000;
int32_t bandwidth = DEFAULT_BANDWIDTH;
uint32_t samp_rate = DEFAULT_SAMPLE_RATE;
uint32_t out_block_size = DEFAULT_BUF_LENGTH;

AudioProcesser::AudioProcesser()
{


}

int AudioProcesser::StartRecording(void)
{
    iq_sink = gr::blocks::file_sink::make(sizeof(gr_complex), "abc", true);
    tb->lock();

//    if (d_decim >= 2)
//        tb->connect(input_decim, 0, iq_sink, 0);
//    else
        tb->connect(src, 0, iq_sink, 0);
   // d_recording_iq = true;
    tb->unlock();
    return -1;
}

/**
static void rtlsdr_callback(unsigned char *buf, uint32_t len, void *ctx)
{
    if (ctx) {
        if (do_exit)
            return;

        if ((iq_frames_to_read) && (iq_frames_to_read < len/2)) {
            len = 2U * iq_frames_to_read;
            iq_frames_to_read = 0;
            do_exit = 1;
            rtlsdr_cancel_async(dev);
        }

        if (!waveHdrStarted) {
            size_t wr = fwrite(buf, 1, len, (FILE*)ctx);
            if ( wr != len) {
                fprintf(stderr, "Short write (wrote %ld of %ld bytes), samples lost, exiting!\n"
                        , (long)wr, (long)len );
                rtlsdr_cancel_async(dev);
            }
        } else {
            if ( waveWriteFrames((FILE*)ctx, buf, len/2, 0) ) {
                fprintf(stderr, "Short write, samples lost, exiting!\n");
                rtlsdr_cancel_async(dev);
            }
        }

        if (iq_frames_to_read) {
            if (iq_frames_to_read > len/2)
                iq_frames_to_read -= len/2;
            else {
                do_exit = 1;
                rtlsdr_cancel_async(dev);
            }
        }
    }
}**/

int AudioProcesser::OpenSdr()
{
    int dev_index = 0;
	int r = rtlsdr_open(&dev,dev_index);
	if (r < 0) {
		fprintf(stderr, "Failed to open rtlsdr device #%d.\n", dev_index);
		return -1;
	}
    qDebug() << "Opening SDR ... \n" ;
    src = osmosdr::source::make(rtlsdr_get_device_name(dev_index));
    return 0;
}

int AudioProcesser::CloseSdr()
{
    //printf("Closing SDR ... \n");
    qDebug() << "Closing SDR ... \n";
    int r = rtlsdr_close(dev);
	if (r < 0) {
		fprintf(stderr, "Failed to close rtlsdr device.\n");
		exit(1);
	}
    return 0;
}

int AudioProcesser::StartStreaming()
{
//    FILE *file;
//	file = stdout;

//    if(dev == NULL)
//    {
//        //printf("dev is NULL");
//        qDebug() << "dev is NULL";
//        return -1;
//    }

//     rtlsdr_set_center_freq(dev,frequency);
//     rtlsdr_set_sample_rate(dev,samp_rate);
//     rtlsdr_set_tuner_gain_mode(dev,0);
//	 uint32_t applied_bw = 0;
//	 rtlsdr_set_and_get_tuner_bandwidth(dev, bandwidth, &applied_bw, 1 /* =apply_bw */);
//	 rtlsdr_reset_buffer(dev);
	
//    rtlsdr_read_async(dev, rtlsdr_callback, (void *)file,
//				      0, out_block_size);
    return 0;
}

int AudioProcesser::StopStreaming()
{
    return -1;
}


int AudioProcesser::CaptureSamples(void)
{
    //printf("Capturing samples ... \n");
    qDebug() << "Capturing samples ... \n";
    FILE *file;
    file = fopen("/home/dlulanemike/dev/asr/AudioProcesserGui/datasets/file_speech_analyis_no_speech.bin", "wb");
    if (!file)
    {
        qDebug() << "Failed to open " <<file<<"\n";
        return -1;
    }
    else
    {
        qDebug() << "Opened file " <<file<<"\n";
    }
    if(dev == NULL)
    {
        //printf("dev is NULL");
        qDebug() << "dev is NULL";
        return -1;
    }
//    rtlsdr_set_center_freq(dev,frequency);
//    rtlsdr_set_sample_rate(dev,samp_rate);
//    rtlsdr_set_tuner_gain_mode(dev,0);
//    uint32_t applied_bw = 0;
//    rtlsdr_set_and_get_tuner_bandwidth(dev, bandwidth, &applied_bw, 1 /* =apply_bw */);
//    rtlsdr_reset_buffer(dev);
//    rtlsdr_read_async(dev, rtlsdr_callback, (void *)file,
//                      0, out_block_size);
//    qDebug() << "Closing file \n";
    fclose(file);
    return 0;
}


AudioProcesser:: ~AudioProcesser()
{
   //top_block_->stop();
}
