#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFF_SIZE 1024

/**
 * error_and_exit - prints the error message and exits with status 98
 * @msg: error message to print
 */
void error_and_exit(char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * print_magic - prints the magic numbers of the elf header
 * @e_ident: array of size EI_NIDENT containing the magic numbers
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT - 1; i++)
		printf("%02x ", e_ident[i]);

	printf("%02x\n", e_ident[i]);
}

/**
 * print_class - prints the class of the elf file
 * @e_ident: array of size EI_NIDENT containing the class info
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
			break;
	}
}

/**
 * print_data - prints the data encoding of the elf file
 * @e_ident: array of size EI_NIDENT containing the data encoding info
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_DATA]);
			break;
	}
}

/**
 * print_version - prints the ELF version
 * @e_ident: array of size EI_NIDENT containing the ELF version info
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           ");

	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf("%d (current)\n", e_ident[EI_VERSION]);
	else
		printf("%d\n", e_ident[EI_VERSION]);
}

/**
 * print_osabi - prints the operating system / ABI used by the elf file
 * @osabi: array of size EI_NIDENT containing the OS/ABI info
 */
void print_osabi(unsigned char osabi)
{
	printf("OS/ABI:\t\t\t\t");

	switch (osabi)
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_AIX:
			printf("UNIX - AIX\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_MODESTO:
			printf("Novell - Modesto\n");
			break;
		case ELFOSABI_OPENBSD:
			printf("UNIX - OpenBSD\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: 0x%x>\n", osabi);
			break;
	}
}
/**
 * main - copy the contents of a file to another file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, or an error code
 */
int main(int argc, char *argv[])
{
	int fd, rd;
	unsigned char buff[BUFF_SIZE];
	Elf64_Ehdr *header;

	if (argc != 2)
		error_and_exit("Usage: elf_header elf_filename");

	/* Open the file */
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_and_exit("Error opening file");

	/* Read ELF header */
	rd = read(fd, buff, BUFF_SIZE);
	if (rd == -1)
		error_and_exit("Error reading file");

	/* Check ELF magic number */
	header = (Elf64_Ehdr *) buff;
	if (header->e_ident[EI_MAG0] != ELFMAG0 ||
	header->e_ident[EI_MAG1] != ELFMAG1 ||
	header->e_ident[EI_MAG2] != ELFMAG2 ||
	header->e_ident[EI_MAG3] != ELFMAG3)
		error_and_exit("File is not an ELF");

	/* Print ELF header information */
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident[EI_OSABI]);

	/* Close file */
	if (close(fd) == -1)
		error_and_exit("Error closing file");

	return (0);
}

