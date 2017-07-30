/*********************************************************************************
 *  ARC-SRTK - Single Frequency RTK Pisitioning Library
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 *  Created on: July 13, 2017
 *********************************************************************************/

#include "arc.h"

const double ff_ratio_table1[31*64]={
        0.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 ,
        0.0010 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 ,
        0.0012 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9700 , 0.9700 , 0.9700 , 0.9800 , 0.9800 , 0.9800 , 0.9800 , 0.9800 , 0.9800 , 0.9800 , 0.9800 , 0.9800 , 0.9800 , 0.9800 , 0.9800 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 ,
        0.0015 , 0.8700 , 0.8700 , 0.8800 , 0.8800 , 0.8900 , 0.8900 , 0.8900 , 0.8900 , 0.9100 , 0.9200 , 0.9200 , 0.9200 , 0.9200 , 0.9300 , 0.9300 , 0.9300 , 0.9300 , 0.9300 , 0.9300 , 0.9300 , 0.9300 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9500 , 0.9500 , 0.9500 , 0.9500 , 0.9500 , 0.9500 , 0.9500 , 0.9500 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9600 , 0.9700 , 0.9700 , 0.9700 , 0.9700 , 0.9700 , 0.9700 , 0.9700 , 0.9700 , 0.9700 , 0.9700 , 0.9700 , 0.9700 , 0.9700 ,
        0.0020 , 0.7800 , 0.7800 , 0.8000 , 0.8000 , 0.8100 , 0.8200 , 0.8300 , 0.8400 , 0.8400 , 0.8600 , 0.8600 , 0.8600 , 0.8700 , 0.8800 , 0.8800 , 0.8800 , 0.8900 , 0.8900 , 0.9000 , 0.9000 , 0.9000 , 0.9000 , 0.9000 , 0.9000 , 0.9100 , 0.9100 , 0.9100 , 0.9200 , 0.9200 , 0.9200 , 0.9200 , 0.9300 , 0.9300 , 0.9300 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9500 , 0.9500 , 0.9500 , 0.9500 , 0.9500 , 0.9500 , 0.9500 , 0.9500 , 0.9500 , 0.9500 , 0.9500 , 0.9500 , 0.9600 ,
        0.0050 , 0.5400 , 0.5400 , 0.5700 , 0.5700 , 0.5900 , 0.6400 , 0.6400 , 0.6800 , 0.6800 , 0.6900 , 0.7100 , 0.7200 , 0.7300 , 0.7400 , 0.7500 , 0.7500 , 0.7700 , 0.7800 , 0.8000 , 0.8000 , 0.8000 , 0.8000 , 0.8000 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8500 , 0.8500 , 0.8600 , 0.8600 , 0.8600 , 0.8600 , 0.8700 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8900 , 0.8900 , 0.8900 , 0.9100 , 0.9100 , 0.9100 , 0.9100 , 0.9100 , 0.9100 , 0.9100 , 0.9100 , 0.9100 , 0.9100 , 0.9100 , 0.9100 , 0.9100 ,
        0.0100 , 0.3600 , 0.3800 , 0.4100 , 0.4300 , 0.4500 , 0.5100 , 0.5200 , 0.5700 , 0.5700 , 0.5900 , 0.6100 , 0.6200 , 0.6400 , 0.6500 , 0.6700 , 0.6700 , 0.6800 , 0.6900 , 0.7200 , 0.7200 , 0.7200 , 0.7200 , 0.7200 , 0.7400 , 0.7600 , 0.7600 , 0.7700 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8700 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8800 ,
        0.0150 , 0.2700 , 0.2900 , 0.3200 , 0.3600 , 0.3800 , 0.4300 , 0.4600 , 0.5100 , 0.5200 , 0.5300 , 0.5500 , 0.5600 , 0.5800 , 0.6000 , 0.6200 , 0.6200 , 0.6400 , 0.6500 , 0.6700 , 0.6700 , 0.6900 , 0.6900 , 0.6900 , 0.7100 , 0.7400 , 0.7400 , 0.7400 , 0.7600 , 0.7600 , 0.7600 , 0.7700 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8500 , 0.8500 , 0.8600 , 0.8600 , 0.8600 , 0.8600 , 0.8600 , 0.8600 , 0.8600 , 0.8700 , 0.8700 , 0.8700 , 0.8800 ,
        0.0200 , 0.2100 , 0.2400 , 0.2700 , 0.3000 , 0.3300 , 0.3800 , 0.4200 , 0.4600 , 0.4800 , 0.4900 , 0.5200 , 0.5200 , 0.5500 , 0.5700 , 0.5900 , 0.5900 , 0.6200 , 0.6200 , 0.6500 , 0.6500 , 0.6700 , 0.6700 , 0.6700 , 0.7000 , 0.7200 , 0.7200 , 0.7200 , 0.7400 , 0.7500 , 0.7500 , 0.7500 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.8000 , 0.8100 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8400 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8600 , 0.8600 , 0.8600 , 0.8700 ,
        0.0250 , 0.1900 , 0.2200 , 0.2400 , 0.2700 , 0.2900 , 0.3500 , 0.3900 , 0.4200 , 0.4500 , 0.4600 , 0.4900 , 0.4900 , 0.5300 , 0.5400 , 0.5600 , 0.5600 , 0.6000 , 0.6000 , 0.6300 , 0.6400 , 0.6500 , 0.6600 , 0.6600 , 0.6800 , 0.7100 , 0.7100 , 0.7100 , 0.7200 , 0.7200 , 0.7300 , 0.7400 , 0.7500 , 0.7500 , 0.7700 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8000 , 0.8100 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8600 , 0.8600 , 0.8600 , 0.8700 ,
        0.0300 , 0.1700 , 0.2000 , 0.2200 , 0.2400 , 0.2600 , 0.3200 , 0.3500 , 0.4000 , 0.4200 , 0.4400 , 0.4700 , 0.4700 , 0.5100 , 0.5300 , 0.5400 , 0.5500 , 0.5800 , 0.5900 , 0.6200 , 0.6200 , 0.6400 , 0.6500 , 0.6500 , 0.6700 , 0.7000 , 0.7000 , 0.7000 , 0.7100 , 0.7100 , 0.7200 , 0.7300 , 0.7400 , 0.7500 , 0.7600 , 0.7600 , 0.7600 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8100 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8400 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8600 , 0.8600 , 0.8600 ,
        0.0350 , 0.1600 , 0.1800 , 0.2000 , 0.2200 , 0.2400 , 0.3000 , 0.3300 , 0.3800 , 0.4000 , 0.4200 , 0.4500 , 0.4500 , 0.4900 , 0.5100 , 0.5300 , 0.5400 , 0.5700 , 0.5800 , 0.6100 , 0.6100 , 0.6300 , 0.6400 , 0.6500 , 0.6600 , 0.6900 , 0.6900 , 0.6900 , 0.7100 , 0.7100 , 0.7200 , 0.7200 , 0.7400 , 0.7400 , 0.7500 , 0.7500 , 0.7600 , 0.7600 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.7900 , 0.8000 , 0.8100 , 0.8100 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8400 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8600 , 0.8600 ,
        0.0400 , 0.1500 , 0.1700 , 0.1800 , 0.2100 , 0.2200 , 0.2700 , 0.3100 , 0.3600 , 0.3900 , 0.4000 , 0.4400 , 0.4400 , 0.4800 , 0.5000 , 0.5200 , 0.5300 , 0.5600 , 0.5600 , 0.6000 , 0.6100 , 0.6200 , 0.6400 , 0.6500 , 0.6600 , 0.6800 , 0.6900 , 0.6900 , 0.7000 , 0.7100 , 0.7100 , 0.7100 , 0.7300 , 0.7400 , 0.7400 , 0.7500 , 0.7500 , 0.7600 , 0.7600 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.7900 , 0.8000 , 0.8100 , 0.8100 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8300 , 0.8400 , 0.8400 , 0.8400 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8600 ,
        0.0450 , 0.1400 , 0.1600 , 0.1700 , 0.1900 , 0.2100 , 0.2600 , 0.2900 , 0.3400 , 0.3800 , 0.3900 , 0.4300 , 0.4400 , 0.4800 , 0.4900 , 0.5100 , 0.5200 , 0.5600 , 0.5600 , 0.5900 , 0.6000 , 0.6100 , 0.6300 , 0.6500 , 0.6500 , 0.6700 , 0.6800 , 0.6800 , 0.7000 , 0.7100 , 0.7100 , 0.7100 , 0.7300 , 0.7300 , 0.7400 , 0.7400 , 0.7500 , 0.7500 , 0.7600 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8100 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8500 , 0.8500 , 0.8600 ,
        0.0500 , 0.1300 , 0.1500 , 0.1600 , 0.1800 , 0.1900 , 0.2400 , 0.2800 , 0.3200 , 0.3700 , 0.3900 , 0.4200 , 0.4300 , 0.4700 , 0.4800 , 0.5100 , 0.5200 , 0.5500 , 0.5500 , 0.5900 , 0.6000 , 0.6100 , 0.6300 , 0.6400 , 0.6400 , 0.6700 , 0.6800 , 0.6800 , 0.6900 , 0.7100 , 0.7100 , 0.7100 , 0.7200 , 0.7300 , 0.7400 , 0.7400 , 0.7500 , 0.7500 , 0.7600 , 0.7600 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.7900 , 0.8000 , 0.8100 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8500 , 0.8600 ,
        0.0550 , 0.1200 , 0.1400 , 0.1500 , 0.1700 , 0.1800 , 0.2300 , 0.2700 , 0.3100 , 0.3600 , 0.3800 , 0.4100 , 0.4200 , 0.4600 , 0.4800 , 0.5000 , 0.5100 , 0.5400 , 0.5500 , 0.5800 , 0.5900 , 0.6000 , 0.6200 , 0.6400 , 0.6400 , 0.6600 , 0.6700 , 0.6800 , 0.6900 , 0.7000 , 0.7000 , 0.7000 , 0.7200 , 0.7300 , 0.7300 , 0.7400 , 0.7500 , 0.7500 , 0.7500 , 0.7600 , 0.7700 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8500 , 0.8600 ,
        0.0600 , 0.1200 , 0.1300 , 0.1500 , 0.1600 , 0.1700 , 0.2100 , 0.2600 , 0.3000 , 0.3600 , 0.3700 , 0.4000 , 0.4200 , 0.4600 , 0.4700 , 0.5000 , 0.5100 , 0.5400 , 0.5400 , 0.5800 , 0.5900 , 0.6000 , 0.6200 , 0.6300 , 0.6300 , 0.6600 , 0.6700 , 0.6700 , 0.6900 , 0.7000 , 0.7000 , 0.7000 , 0.7100 , 0.7200 , 0.7300 , 0.7400 , 0.7400 , 0.7500 , 0.7500 , 0.7600 , 0.7600 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8100 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8500 , 0.8600 ,
        0.0650 , 0.1100 , 0.1200 , 0.1400 , 0.1500 , 0.1600 , 0.2000 , 0.2600 , 0.3000 , 0.3500 , 0.3600 , 0.4000 , 0.4100 , 0.4500 , 0.4600 , 0.5000 , 0.5100 , 0.5300 , 0.5400 , 0.5800 , 0.5900 , 0.5900 , 0.6100 , 0.6300 , 0.6300 , 0.6600 , 0.6700 , 0.6700 , 0.6800 , 0.7000 , 0.7000 , 0.7000 , 0.7100 , 0.7200 , 0.7300 , 0.7300 , 0.7400 , 0.7500 , 0.7500 , 0.7600 , 0.7600 , 0.7700 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8100 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8500 , 0.8500 ,
        0.0700 , 0.1100 , 0.1200 , 0.1300 , 0.1400 , 0.1500 , 0.2000 , 0.2500 , 0.3000 , 0.3500 , 0.3600 , 0.3900 , 0.4100 , 0.4500 , 0.4600 , 0.4900 , 0.5000 , 0.5300 , 0.5400 , 0.5800 , 0.5800 , 0.5900 , 0.6100 , 0.6300 , 0.6300 , 0.6600 , 0.6600 , 0.6700 , 0.6800 , 0.6900 , 0.6900 , 0.7000 , 0.7100 , 0.7200 , 0.7300 , 0.7300 , 0.7400 , 0.7400 , 0.7500 , 0.7600 , 0.7600 , 0.7700 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7800 , 0.7900 , 0.8000 , 0.8000 , 0.8100 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8500 , 0.8500 ,
        0.0750 , 0.1000 , 0.1100 , 0.1200 , 0.1300 , 0.1500 , 0.1900 , 0.2400 , 0.2900 , 0.3400 , 0.3600 , 0.3900 , 0.4100 , 0.4400 , 0.4500 , 0.4900 , 0.5000 , 0.5200 , 0.5400 , 0.5700 , 0.5800 , 0.5900 , 0.6100 , 0.6300 , 0.6300 , 0.6500 , 0.6600 , 0.6700 , 0.6800 , 0.6900 , 0.6900 , 0.6900 , 0.7100 , 0.7200 , 0.7300 , 0.7300 , 0.7400 , 0.7400 , 0.7500 , 0.7600 , 0.7600 , 0.7700 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7800 , 0.7900 , 0.8000 , 0.8000 , 0.8000 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8500 ,
        0.0800 , 0.1000 , 0.1000 , 0.1200 , 0.1300 , 0.1400 , 0.1900 , 0.2300 , 0.2900 , 0.3400 , 0.3500 , 0.3800 , 0.4000 , 0.4400 , 0.4500 , 0.4900 , 0.5000 , 0.5200 , 0.5300 , 0.5700 , 0.5800 , 0.5900 , 0.6100 , 0.6200 , 0.6200 , 0.6500 , 0.6600 , 0.6700 , 0.6800 , 0.6900 , 0.6900 , 0.6900 , 0.7100 , 0.7200 , 0.7300 , 0.7300 , 0.7400 , 0.7400 , 0.7500 , 0.7600 , 0.7600 , 0.7600 , 0.7700 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8000 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8500 ,
        0.0850 , 0.1000 , 0.1000 , 0.1100 , 0.1200 , 0.1400 , 0.1800 , 0.2300 , 0.2800 , 0.3300 , 0.3500 , 0.3800 , 0.4000 , 0.4400 , 0.4500 , 0.4900 , 0.5000 , 0.5100 , 0.5300 , 0.5700 , 0.5800 , 0.5900 , 0.6100 , 0.6200 , 0.6200 , 0.6500 , 0.6600 , 0.6700 , 0.6800 , 0.6800 , 0.6900 , 0.6900 , 0.7100 , 0.7200 , 0.7300 , 0.7300 , 0.7400 , 0.7400 , 0.7500 , 0.7600 , 0.7600 , 0.7600 , 0.7600 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8000 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8500 ,
        0.0900 , 0.0900 , 0.0900 , 0.1100 , 0.1200 , 0.1300 , 0.1800 , 0.2200 , 0.2800 , 0.3300 , 0.3500 , 0.3800 , 0.4000 , 0.4300 , 0.4500 , 0.4900 , 0.5000 , 0.5100 , 0.5300 , 0.5600 , 0.5800 , 0.5900 , 0.6100 , 0.6200 , 0.6200 , 0.6500 , 0.6600 , 0.6600 , 0.6700 , 0.6700 , 0.6900 , 0.6900 , 0.7100 , 0.7100 , 0.7300 , 0.7300 , 0.7300 , 0.7400 , 0.7500 , 0.7600 , 0.7600 , 0.7600 , 0.7600 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8000 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8500 ,
        0.0950 , 0.0900 , 0.0900 , 0.1000 , 0.1100 , 0.1300 , 0.1800 , 0.2200 , 0.2800 , 0.3300 , 0.3400 , 0.3800 , 0.4000 , 0.4300 , 0.4500 , 0.4800 , 0.4900 , 0.5100 , 0.5300 , 0.5600 , 0.5700 , 0.5900 , 0.6100 , 0.6200 , 0.6200 , 0.6500 , 0.6500 , 0.6600 , 0.6700 , 0.6700 , 0.6800 , 0.6900 , 0.7100 , 0.7100 , 0.7200 , 0.7300 , 0.7300 , 0.7400 , 0.7500 , 0.7500 , 0.7600 , 0.7600 , 0.7600 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8000 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8500 ,
        0.1000 , 0.0900 , 0.0900 , 0.1000 , 0.1100 , 0.1200 , 0.1700 , 0.2200 , 0.2700 , 0.3200 , 0.3400 , 0.3700 , 0.4000 , 0.4300 , 0.4400 , 0.4800 , 0.4900 , 0.5100 , 0.5300 , 0.5600 , 0.5700 , 0.5800 , 0.6100 , 0.6200 , 0.6200 , 0.6400 , 0.6500 , 0.6600 , 0.6700 , 0.6700 , 0.6800 , 0.6900 , 0.7100 , 0.7100 , 0.7200 , 0.7300 , 0.7300 , 0.7400 , 0.7500 , 0.7500 , 0.7600 , 0.7600 , 0.7600 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8000 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8400 , 0.8500 ,
        0.1200 , 0.0800 , 0.0800 , 0.0900 , 0.0900 , 0.1100 , 0.1600 , 0.2100 , 0.2600 , 0.3100 , 0.3300 , 0.3700 , 0.3900 , 0.4200 , 0.4400 , 0.4800 , 0.4900 , 0.5100 , 0.5300 , 0.5500 , 0.5700 , 0.5800 , 0.6000 , 0.6100 , 0.6100 , 0.6400 , 0.6400 , 0.6600 , 0.6700 , 0.6700 , 0.6800 , 0.6800 , 0.7000 , 0.7100 , 0.7200 , 0.7200 , 0.7300 , 0.7400 , 0.7400 , 0.7500 , 0.7600 , 0.7600 , 0.7600 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8100 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8400 , 0.8400 ,
        0.1500 , 0.0700 , 0.0700 , 0.0800 , 0.0800 , 0.1000 , 0.1600 , 0.2000 , 0.2500 , 0.2900 , 0.3200 , 0.3500 , 0.3900 , 0.4100 , 0.4400 , 0.4700 , 0.4900 , 0.5000 , 0.5200 , 0.5500 , 0.5600 , 0.5700 , 0.6000 , 0.6100 , 0.6100 , 0.6400 , 0.6400 , 0.6600 , 0.6600 , 0.6600 , 0.6800 , 0.6800 , 0.7000 , 0.7100 , 0.7100 , 0.7200 , 0.7300 , 0.7300 , 0.7400 , 0.7500 , 0.7600 , 0.7600 , 0.7600 , 0.7600 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.7900 , 0.8000 , 0.8100 , 0.8100 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8400 , 0.8400 ,
        0.2000 , 0.0500 , 0.0500 , 0.0600 , 0.0600 , 0.1000 , 0.1500 , 0.1900 , 0.2400 , 0.2700 , 0.3100 , 0.3400 , 0.3800 , 0.4100 , 0.4300 , 0.4600 , 0.4800 , 0.5000 , 0.5100 , 0.5400 , 0.5500 , 0.5700 , 0.5900 , 0.6000 , 0.6100 , 0.6400 , 0.6400 , 0.6500 , 0.6600 , 0.6600 , 0.6800 , 0.6800 , 0.7000 , 0.7100 , 0.7100 , 0.7100 , 0.7300 , 0.7300 , 0.7400 , 0.7500 , 0.7600 , 0.7600 , 0.7600 , 0.7600 , 0.7600 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8100 , 0.8100 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8300 , 0.8400 ,
        0.2500 , 0.0400 , 0.0400 , 0.0500 , 0.0600 , 0.0900 , 0.1400 , 0.1800 , 0.2300 , 0.2500 , 0.3000 , 0.3400 , 0.3700 , 0.4100 , 0.4300 , 0.4600 , 0.4700 , 0.5000 , 0.5100 , 0.5400 , 0.5500 , 0.5700 , 0.5900 , 0.6000 , 0.6000 , 0.6300 , 0.6400 , 0.6500 , 0.6600 , 0.6600 , 0.6800 , 0.6800 , 0.7000 , 0.7000 , 0.7100 , 0.7100 , 0.7300 , 0.7300 , 0.7400 , 0.7500 , 0.7500 , 0.7600 , 0.7600 , 0.7600 , 0.7600 , 0.7700 , 0.7700 , 0.7700 , 0.7800 , 0.7800 , 0.7900 , 0.8000 , 0.8000 , 0.8100 , 0.8100 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8400 ,
        0.2600 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 ,
        1.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000
};
/*----------------------------------------------------------------------------------------------------------------------------------------------*/
const double ff_ratio_table2[31*41]={
        0.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 ,
        0.0100 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 ,
        0.0110 , 0.9600 , 0.9700 , 0.9700 , 0.9700 , 0.9700 , 0.9800 , 0.9800 , 0.9800 , 0.9800 , 0.9800 , 0.9800 , 0.9700 , 0.9800 , 0.9800 , 0.9800 , 0.9800 , 0.9800 , 0.9800 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 0.9900 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 , 1.0000 ,
        0.0160 , 0.8000 , 0.8100 , 0.8300 , 0.8400 , 0.8500 , 0.8800 , 0.8800 , 0.8800 , 0.8900 , 0.9000 , 0.9000 , 0.9000 , 0.9100 , 0.9100 , 0.9200 , 0.9100 , 0.9200 , 0.9300 , 0.9300 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9400 , 0.9500 , 0.9500 , 0.9500 , 0.9600 , 0.9600 , 0.9500 , 0.9600 , 0.9800 , 0.9800 , 0.9800 , 0.9800 , 0.9800 , 0.9800 , 0.9800 , 0.9800 , 0.9800 ,
        0.0210 , 0.6800 , 0.7000 , 0.7200 , 0.7400 , 0.7600 , 0.8000 , 0.8000 , 0.8200 , 0.8300 , 0.8400 , 0.8400 , 0.8500 , 0.8600 , 0.8700 , 0.8800 , 0.8700 , 0.8800 , 0.8900 , 0.8900 , 0.9000 , 0.9000 , 0.9100 , 0.9100 , 0.9100 , 0.9200 , 0.9200 , 0.9200 , 0.9300 , 0.9300 , 0.9300 , 0.9400 , 0.9500 , 0.9500 , 0.9500 , 0.9500 , 0.9500 , 0.9500 , 0.9500 , 0.9500 , 0.9500 ,
        0.0260 , 0.5900 , 0.6100 , 0.6400 , 0.6700 , 0.7000 , 0.7300 , 0.7400 , 0.7800 , 0.7900 , 0.8000 , 0.8000 , 0.8100 , 0.8200 , 0.8400 , 0.8400 , 0.8400 , 0.8500 , 0.8700 , 0.8700 , 0.8800 , 0.8800 , 0.8800 , 0.8900 , 0.8900 , 0.9000 , 0.9000 , 0.9000 , 0.9100 , 0.9100 , 0.9100 , 0.9200 , 0.9300 , 0.9300 , 0.9300 , 0.9300 , 0.9300 , 0.9300 , 0.9300 , 0.9300 , 0.9300 ,
        0.0310 , 0.5200 , 0.5500 , 0.5800 , 0.6200 , 0.6500 , 0.6800 , 0.7000 , 0.7400 , 0.7600 , 0.7700 , 0.7700 , 0.7800 , 0.7900 , 0.8100 , 0.8200 , 0.8300 , 0.8400 , 0.8400 , 0.8500 , 0.8500 , 0.8600 , 0.8700 , 0.8700 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8900 , 0.8900 , 0.8900 , 0.9000 , 0.9100 , 0.9100 , 0.9100 , 0.9100 , 0.9100 , 0.9100 , 0.9100 , 0.9100 , 0.9100 ,
        0.0360 , 0.4800 , 0.5100 , 0.5400 , 0.5700 , 0.6000 , 0.6400 , 0.6700 , 0.7100 , 0.7300 , 0.7400 , 0.7500 , 0.7500 , 0.7700 , 0.7900 , 0.8000 , 0.8100 , 0.8200 , 0.8300 , 0.8300 , 0.8400 , 0.8500 , 0.8500 , 0.8600 , 0.8600 , 0.8700 , 0.8700 , 0.8700 , 0.8800 , 0.8800 , 0.8800 , 0.8900 , 0.8900 , 0.8900 , 0.8900 , 0.8900 , 0.8900 , 0.8900 , 0.8900 , 0.8900 , 0.8900 ,
        0.0410 , 0.4400 , 0.4700 , 0.5000 , 0.5300 , 0.5500 , 0.6100 , 0.6400 , 0.6900 , 0.7000 , 0.7200 , 0.7300 , 0.7400 , 0.7500 , 0.7700 , 0.7800 , 0.7900 , 0.8000 , 0.8100 , 0.8200 , 0.8200 , 0.8300 , 0.8400 , 0.8500 , 0.8500 , 0.8500 , 0.8600 , 0.8600 , 0.8700 , 0.8700 , 0.8700 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8800 , 0.8800 ,
        0.0460 , 0.4100 , 0.4400 , 0.4800 , 0.5000 , 0.5200 , 0.5800 , 0.6200 , 0.6700 , 0.6800 , 0.7000 , 0.7100 , 0.7200 , 0.7400 , 0.7600 , 0.7600 , 0.7800 , 0.7900 , 0.8000 , 0.8000 , 0.8100 , 0.8200 , 0.8300 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8500 , 0.8600 , 0.8600 , 0.8700 , 0.8700 , 0.8700 , 0.8700 , 0.8700 , 0.8700 , 0.8700 , 0.8700 , 0.8700 , 0.8700 , 0.8700 ,
        0.0510 , 0.3900 , 0.4200 , 0.4500 , 0.4800 , 0.5000 , 0.5600 , 0.6000 , 0.6500 , 0.6600 , 0.6800 , 0.6900 , 0.7000 , 0.7200 , 0.7400 , 0.7500 , 0.7700 , 0.7800 , 0.7900 , 0.7900 , 0.8000 , 0.8100 , 0.8200 , 0.8300 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8500 , 0.8600 , 0.8600 , 0.8600 , 0.8700 , 0.8700 , 0.8700 , 0.8700 , 0.8700 , 0.8700 , 0.8700 , 0.8700 , 0.8700 ,
        0.0560 , 0.3700 , 0.4000 , 0.4300 , 0.4500 , 0.4700 , 0.5400 , 0.5800 , 0.6300 , 0.6400 , 0.6600 , 0.6700 , 0.6900 , 0.7100 , 0.7300 , 0.7400 , 0.7600 , 0.7700 , 0.7800 , 0.7800 , 0.7900 , 0.8000 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8500 , 0.8500 , 0.8500 , 0.8600 , 0.8600 , 0.8600 , 0.8600 , 0.8600 , 0.8600 , 0.8600 , 0.8600 , 0.8600 , 0.8600 ,
        0.0610 , 0.3500 , 0.3800 , 0.4100 , 0.4300 , 0.4500 , 0.5200 , 0.5600 , 0.6200 , 0.6300 , 0.6400 , 0.6600 , 0.6800 , 0.7000 , 0.7200 , 0.7300 , 0.7500 , 0.7600 , 0.7700 , 0.7800 , 0.7800 , 0.7900 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8200 , 0.8300 , 0.8400 , 0.8400 , 0.8500 , 0.8500 , 0.8600 , 0.8600 , 0.8600 , 0.8600 , 0.8600 , 0.8600 , 0.8600 , 0.8600 , 0.8600 ,
        0.0660 , 0.3300 , 0.3600 , 0.3900 , 0.4100 , 0.4400 , 0.5000 , 0.5500 , 0.6000 , 0.6200 , 0.6300 , 0.6500 , 0.6700 , 0.6900 , 0.7100 , 0.7200 , 0.7400 , 0.7500 , 0.7600 , 0.7700 , 0.7800 , 0.7800 , 0.8100 , 0.8100 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8400 , 0.8400 , 0.8400 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8500 ,
        0.0710 , 0.3200 , 0.3500 , 0.3700 , 0.4000 , 0.4200 , 0.4900 , 0.5400 , 0.5900 , 0.6100 , 0.6200 , 0.6400 , 0.6600 , 0.6800 , 0.7000 , 0.7100 , 0.7300 , 0.7400 , 0.7500 , 0.7600 , 0.7700 , 0.7800 , 0.8000 , 0.8000 , 0.8100 , 0.8100 , 0.8100 , 0.8200 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8500 , 0.8500 ,
        0.0760 , 0.3100 , 0.3400 , 0.3600 , 0.3800 , 0.4000 , 0.4800 , 0.5200 , 0.5800 , 0.6000 , 0.6100 , 0.6300 , 0.6500 , 0.6700 , 0.7000 , 0.7100 , 0.7200 , 0.7300 , 0.7500 , 0.7600 , 0.7700 , 0.7700 , 0.8000 , 0.8000 , 0.8000 , 0.8100 , 0.8100 , 0.8100 , 0.8300 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 ,
        0.0810 , 0.3000 , 0.3200 , 0.3500 , 0.3700 , 0.3900 , 0.4700 , 0.5100 , 0.5700 , 0.5900 , 0.6100 , 0.6200 , 0.6400 , 0.6600 , 0.6900 , 0.7000 , 0.7100 , 0.7300 , 0.7400 , 0.7500 , 0.7600 , 0.7700 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8100 , 0.8100 , 0.8200 , 0.8300 , 0.8300 , 0.8300 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 ,
        0.0860 , 0.2900 , 0.3100 , 0.3400 , 0.3600 , 0.3800 , 0.4500 , 0.5000 , 0.5700 , 0.5800 , 0.6000 , 0.6100 , 0.6300 , 0.6600 , 0.6800 , 0.6900 , 0.7100 , 0.7200 , 0.7400 , 0.7500 , 0.7600 , 0.7600 , 0.7900 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8300 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 ,
        0.0910 , 0.2800 , 0.3100 , 0.3300 , 0.3500 , 0.3700 , 0.4400 , 0.4900 , 0.5600 , 0.5800 , 0.5900 , 0.6100 , 0.6200 , 0.6500 , 0.6800 , 0.6900 , 0.7000 , 0.7200 , 0.7300 , 0.7400 , 0.7500 , 0.7600 , 0.7800 , 0.7900 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8200 , 0.8200 , 0.8200 , 0.8300 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 , 0.8400 ,
        0.0960 , 0.2700 , 0.3000 , 0.3200 , 0.3400 , 0.3600 , 0.4300 , 0.4800 , 0.5500 , 0.5700 , 0.5900 , 0.6000 , 0.6200 , 0.6400 , 0.6700 , 0.6800 , 0.7000 , 0.7100 , 0.7300 , 0.7400 , 0.7500 , 0.7600 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8100 , 0.8200 , 0.8200 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8300 ,
        0.1200 , 0.2300 , 0.2500 , 0.2700 , 0.3000 , 0.3200 , 0.4000 , 0.4500 , 0.5200 , 0.5400 , 0.5600 , 0.5800 , 0.6000 , 0.6300 , 0.6500 , 0.6600 , 0.6800 , 0.7000 , 0.7100 , 0.7200 , 0.7400 , 0.7400 , 0.7600 , 0.7700 , 0.7700 , 0.7800 , 0.7900 , 0.7900 , 0.8100 , 0.8100 , 0.8100 , 0.8200 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8300 , 0.8300 ,
        0.1500 , 0.1700 , 0.2000 , 0.2300 , 0.2600 , 0.2900 , 0.3700 , 0.4300 , 0.4900 , 0.5100 , 0.5400 , 0.5600 , 0.5900 , 0.6100 , 0.6300 , 0.6500 , 0.6700 , 0.6900 , 0.7000 , 0.7100 , 0.7200 , 0.7300 , 0.7500 , 0.7600 , 0.7600 , 0.7700 , 0.7800 , 0.7900 , 0.8000 , 0.8000 , 0.8000 , 0.8100 , 0.8200 , 0.8200 , 0.8200 , 0.8200 , 0.8200 , 0.8200 , 0.8200 , 0.8200 , 0.8200 ,
        0.2000 , 0.1000 , 0.1400 , 0.1800 , 0.2200 , 0.2600 , 0.3300 , 0.4000 , 0.4500 , 0.4800 , 0.5100 , 0.5400 , 0.5700 , 0.5900 , 0.6200 , 0.6400 , 0.6600 , 0.6700 , 0.6900 , 0.7000 , 0.7100 , 0.7200 , 0.7400 , 0.7500 , 0.7500 , 0.7600 , 0.7700 , 0.7800 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8100 , 0.8100 , 0.8100 , 0.8100 , 0.8100 , 0.8100 , 0.8100 , 0.8100 , 0.8100 ,
        0.2500 , 0.0400 , 0.0900 , 0.1400 , 0.1900 , 0.2400 , 0.3000 , 0.3800 , 0.4200 , 0.4600 , 0.4900 , 0.5200 , 0.5500 , 0.5800 , 0.6100 , 0.6300 , 0.6500 , 0.6600 , 0.6800 , 0.6900 , 0.7100 , 0.7200 , 0.7300 , 0.7400 , 0.7500 , 0.7600 , 0.7700 , 0.7700 , 0.7900 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8000 , 0.8000 , 0.8000 , 0.8000 , 0.8000 , 0.8000 , 0.8000 , 0.8000 ,
        0.3000 , 0.0200 , 0.0700 , 0.1200 , 0.1700 , 0.2100 , 0.2700 , 0.3600 , 0.4000 , 0.4400 , 0.4700 , 0.5100 , 0.5400 , 0.5700 , 0.6000 , 0.6200 , 0.6400 , 0.6500 , 0.6700 , 0.6900 , 0.7000 , 0.7100 , 0.7200 , 0.7300 , 0.7400 , 0.7500 , 0.7600 , 0.7700 , 0.7800 , 0.7900 , 0.7900 , 0.7900 , 0.8000 , 0.8000 , 0.8000 , 0.8000 , 0.8000 , 0.8000 , 0.8000 , 0.8000 , 0.8000 ,
        0.3500 , 0.0100 , 0.0600 , 0.1100 , 0.1500 , 0.2000 , 0.2500 , 0.3500 , 0.3800 , 0.4200 , 0.4700 , 0.5000 , 0.5400 , 0.5600 , 0.5900 , 0.6200 , 0.6300 , 0.6500 , 0.6600 , 0.6800 , 0.7000 , 0.7100 , 0.7100 , 0.7300 , 0.7400 , 0.7500 , 0.7600 , 0.7700 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 ,
        0.4000 , 0.0100 , 0.0600 , 0.1000 , 0.1400 , 0.1800 , 0.2400 , 0.3300 , 0.3700 , 0.4200 , 0.4600 , 0.5000 , 0.5300 , 0.5600 , 0.5900 , 0.6100 , 0.6300 , 0.6500 , 0.6600 , 0.6800 , 0.7000 , 0.7100 , 0.7100 , 0.7300 , 0.7400 , 0.7500 , 0.7600 , 0.7700 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 ,
        0.4500 , 0.0100 , 0.0500 , 0.0900 , 0.1300 , 0.1800 , 0.2300 , 0.3200 , 0.3600 , 0.4100 , 0.4600 , 0.4900 , 0.5300 , 0.5500 , 0.5800 , 0.6100 , 0.6300 , 0.6400 , 0.6600 , 0.6800 , 0.7000 , 0.7100 , 0.7100 , 0.7200 , 0.7300 , 0.7500 , 0.7600 , 0.7700 , 0.7800 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 ,
        0.4990 , 0.0100 , 0.0500 , 0.0900 , 0.1300 , 0.1700 , 0.2200 , 0.3200 , 0.3600 , 0.4100 , 0.4500 , 0.4900 , 0.5200 , 0.5500 , 0.5800 , 0.6100 , 0.6300 , 0.6400 , 0.6500 , 0.6800 , 0.7000 , 0.7100 , 0.7100 , 0.7200 , 0.7300 , 0.7500 , 0.7600 , 0.7600 , 0.7800 , 0.7800 , 0.7800 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 , 0.7900 ,
        0.5000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 ,
        1.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 , 0.0000 ,
};
/*---------------------------------------------------------------------------------------------------------------------------------------------- */