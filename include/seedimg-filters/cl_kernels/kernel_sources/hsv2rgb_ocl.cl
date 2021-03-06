__kernel void hsv2rgb(__global uchar4* inp_pix, __global uchar4* res_pix) {
        ulong num = get_global_id(0);
        float4 pix = convert_float4(inp_pix[num]);
        pix.x *= 2;
        pix.yz /= 100;
        
        float C = pix.y * pix.z;
        float X = C * (1 - fabs(fmod(pix.x / 60.0f, 2.0f) - 1));
        res_pix[num].xyz = convert_uchar3((
        (0 <= pix.x && pix.x < 60) * (float3)(C, X, 0) +
        (60 <= pix.x && pix.x < 120) * (float3)(X, C, 0) +
        (120 <= pix.x && pix.x < 180) * (float3)(0, C, X) +
        (180 <= pix.x && pix.x < 240) * (float3)(C, X, C) +
        (240 <= pix.x && pix.x < 300) * (float3)(X, 0, C) +
        (300 <= pix.x && pix.x < 360) * (float3)(C, 0, X) + pix.z - C) * 255);
}
 
