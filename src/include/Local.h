//
// Created by skidr on 06/05/2020.
//

#ifndef MEETUP_RIDER_LOCAL_H
#define MEETUP_RIDER_LOCAL_H

#include <string>

/**
 * @brief Classe Local
 * Guarda as infomações de um Local
 */
class Local {
    std::string nome; //!< nome do local
public:
    /**
     * @brief Construtor padrão de Local
     * Inicia o atributo nome como "undefined"
     */
    Local();

    /**
     * @brief Construtor de Local
     * @param nome nome do local
     */
    Local(const std::string &nome);

    /**
     * @brief Método GET para o nome
     * @return nome do local
     */
    const std::string &getNome() const;

    /**
     * @brief Método SET para o nome
     * @param nome novo nome do local
     */
    void setNome(const std::string &nome);
};


#endif //MEETUP_RIDER_LOCAL_H
