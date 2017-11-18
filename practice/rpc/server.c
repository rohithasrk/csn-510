#include "square.h"
square_out * squareproc_1_svc(square_in *inp, struct svc_req *rqstp){
    static square_out out;
    sleep(10000);
    out.res1 = inp->arg1 * inp->arg1;
    return(&out);
}
