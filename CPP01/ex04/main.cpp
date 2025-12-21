/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:17:18 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/20 16:54:06 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sedIsForLooser.h"

int	ft_err(std::string mess)
{
	std::cerr << ERR << mess << std::endl;
	return (1);
}

std::string	ft_getContent(std::ifstream &inputFile)
{
	std::string	line;
	std::string	content;

	while (std::getline(inputFile, line))
	{
		content += line;
		content += "\n";
	}
	inputFile.close();
	return (content);
}

void	ft_replace(std::string &content, std::string s1, std::string s2)
{
	std::size_t	sizeS1 = s1.length();
	std::size_t	sizeS2 = s2.length();
	std::size_t	pos = 0;
	
	while ((pos = content.find(s1, pos)) != std::string::npos)
	{
		content.erase(pos, sizeS1);
		content.insert(pos, s2);
		pos += sizeS2;
	}
}

int	ft_isvalid(int argc, char **argv)
{
	std::string	arg(argv[2]);
	if (argc != 4)
		return (ft_err(FORMAT));
	if (arg == "")
		return (ft_err(INV_ARG));
	return (0);
}

int	main(int argc, char **argv)
{
	if (ft_isvalid(argc, argv))
		return (1);
	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
		return (ft_err(ERROPEN));

	std::string	content = ft_getContent(inputFile);
	ft_replace(content, argv[2], argv[3]);

	std::string outputFilename = argv[1];
	outputFilename += FILE_EXT;
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile.is_open())
		return (ft_err(ERRCREATE));

	outputFile << content;
	outputFile.close();
}
