#ifndef AUDIOPROCESSER_H
#define AUDIOPROCESSER_H
#include <iostream>
#include <string>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <rtl-sdr.h>
//#include "wavewrite.h"
//#include "rtl_tcp.h"
#include <QDebug>
#include "convenience.h"
#include "rtl_convenience.h"
#include "wavewrite.h"
#include <gnuradio/blocks/multiply_const.h>
#include <gnuradio/blocks/file_sink.h>
#include <gnuradio/blocks/null_sink.h>
#include <gnuradio/blocks/wavfile_sink.h>
#include <gnuradio/blocks/wavfile_source.h>
#include <gnuradio/top_block.h>
#include <osmosdr/source.h>
#include "../../gqrx.git/src/dsp/filter/fir_decim.h"
#include "../../gqrx.git/src/dsp/correct_iq_cc.h"
class AudioProcesser
        {
 
private:
    gr::top_block_sptr         tb;        /*!< The GNU Radio top block. */
    osmosdr::source::sptr     src;       /*!< Real time I/Q source. */
    fir_decim_cc_sptr         input_decim;
    unsigned int              d_decim;        /*!< input decimation. */
    iq_swap_cc_sptr           iq_swap;   /*!< I/Q swapping block. */
    gr::blocks::file_sink::sptr         iq_sink;     /*!< I/Q file sink. */

public:
  AudioProcesser();
  ~AudioProcesser();
  int OpenSdr(void);
  int CloseSdr(void);
 int StartStreaming(void);
  int StopStreaming(void);
  int CaptureSamples(void);
  int StartRecording(void);
};

#endif //AUDIOPROCESSER_H
