inline float fmodulo(float x, float N) {
  return fmod(x, N) + (fmod(x, N) < 0) * N;
}

__kernel void rgb2hsv(__global uchar4* inp_pix, __global uchar4* res_pix) {
      //size per workgroup
      ulong spw = get_global_size(0) / get_num_groups(0);
      ulong start = spw * get_group_id(0) + get_local_id(0);
      ulong stop = start + spw;
      for(ulong num = start; num < stop; num+=get_local_size(0)) {
        
        float rp = (float)inp_pix[num].x / 255.0f;
        float gp = (float)inp_pix[num].y / 255.0f;
        float bp = (float)inp_pix[num].z / 255.0f;
        
        float cmax = fmax(rp, fmax(gp, bp));
        float cmin = fmin(rp, fmin(gp, bp));
        
        /*
        if(cmax == 0)
            continue;
        */
        
        
        float delta = cmax - cmin;
        
        
        float h = (rp == cmax) * (30 * fmodulo((gp-bp) / delta, 6.0f)) +
                  (gp == cmax) * (60 * ((bp-rp) / delta + 2)) +
                  (bp == cmax) * (60 * ((rp-gp) / delta + 4));
        
        float s = (cmax > 0) * ((delta/cmax)*100.0f);
        
        float v = (cmax * 100.0f);
        
        res_pix[num].xyz = (uchar3)(h,s,v);
      }
}
