OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm",
	      "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)
SECTIONS
{
	. = 0x60000000;

	.text : {
		*(.text);
	}
	. = ALIGN(4);

	.data : {
		*(.data);
	}
	. = ALIGN(4);

	_start_xiaomi = .;
	.xiaomi : {
		*(.xiaomi);
	}
	_end_xiaomi = .;
	. = ALIGN(4);

	_start_bss = .;
	.bss : {
		*(.bss);
	}
	. = ALIGN(4);
	_end_bss = .;
}
