%% DRM transmitter

clear all

clc


%% calculate global variables, for the list of assumptions see drm_global_variables.m
run drm_global_variables

%% create dummy bits (TODO: fill them with real data)
msc_stream = ones(1, MSC.L_MUX); % one MSC multiplex frame
sdc_stream = zeros(1, SDC.L_SDC); % one SDC block
fac_stream = ones(1, FAC.L_FAC); % one FAC block

%% energy dispersal
msc_stream_scrambled = drm_scrambler(msc_stream);
sdc_stream_scrambled = drm_scrambler(sdc_stream);
fac_stream_scrambled = drm_scrambler(fac_stream);

%% partitioning
msc_stream_partitioned = drm_mlc_partitioning(msc_stream_scrambled, 'MSC', MSC);
sdc_stream_partitioned = drm_mlc_partitioning(sdc_stream_scrambled, 'SDC', SDC);
fac_stream_partitioned = drm_mlc_partitioning(fac_stream_scrambled, 'FAC', FAC);

%% encoding
msc_stream_encoded = drm_mlc_encoder(msc_stream_partitioned, 'MSC', MSC);
sdc_stream_encoded = drm_mlc_encoder(sdc_stream_partitioned, 'SDC', SDC);
fac_stream_encoded = drm_mlc_encoder(fac_stream_partitioned, 'FAC', FAC);

%% interleaving
msc_stream_interleaved = drm_mlc_interleaver(msc_stream_encoded, 'MSC', MSC);
sdc_stream_interleaved = drm_mlc_interleaver(sdc_stream_encoded, 'SDC', SDC);
fac_stream_interleaved = drm_mlc_interleaver(fac_stream_encoded, 'FAC', FAC);

%% mapping

%% OFDM, guard interval etc.