#include "drm_config.h"

/* config implementation */
void
config::init(tables* ptr_tables)
{
	std::cout << "init cfg\n";

	/* user defined parameters */
	d_RM = 1; // B
	d_SO = 3; // 10 kHz
	d_UEP = false; // EEP
	d_text = false; // no text message included
	d_long_interl = false; // short interleaving (400ms)
	d_msc_mapping = 0; // 16-QAM SM
	d_sdc_mapping = 1; // 4-QAM
	d_sdc_coderate = 0; // R = 0.5

	/* pointer to tables needed for init */
	d_ptables = ptr_tables;

	/* make some range and combination checks */
	if(!check_arguments())
	{
		std::cout << "INVALID CONFIGURATION!\n";
	}
}

bool
config::check_arguments()
{
	bool valid = true;

	/* check for unsupported values and combinations */

	/* some range checks */
	if (d_RM < 0 || d_RM > 4){ valid = false; }
	if (d_SO < 0 || d_SO > 5){ valid = false; }
	if (d_msc_mapping < 0 || d_msc_mapping > 2){ valid = false; }
	if (d_sdc_mapping < 0 || d_sdc_mapping > 1){ valid = false; }
	if (d_sdc_coderate < 0 || d_sdc_coderate > 1){ valid = false; }

	/* some combination checks */
	if (d_RM == 4 && d_SO != 0){ valid = false; }
	if (( d_RM == 2 || d_RM == 3 ) && d_SO < 3){ valid = false; }
	if (d_RM < 4 && d_sdc_coderate != 0){ valid = false; }

	return valid;
}

unsigned short
config::RM()
{
	return d_RM;
}

unsigned short
config::SO()
{
	return d_SO;
}

bool
config::UEP()
{
	return d_UEP;
}

bool
config::text()
{
	return d_text;
}

bool
config::long_interl()
{
	return d_long_interl;
}

unsigned short
config::msc_mapping()
{
	return d_msc_mapping;
}

unsigned short
config::sdc_mapping()
{
	return d_sdc_mapping;
}

unsigned short
config::sdc_coderate()
{
	return d_sdc_coderate;
}