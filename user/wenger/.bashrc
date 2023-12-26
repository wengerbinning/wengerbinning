
#
PS1='\e[36m\u@\h \e[34m\W \e[31m\$ \e[0m'

#
alias ip='ip -c'
alias ls='ls --color=auto'

# Enable bash completion in interactive shells.
if ! shopt -oq posix; then
    if [ -f /usr/share/bash-completion/bash_completion ]; then
        . /usr/share/bash-completion/bash_completion
    elif [ -f /etc/bash_completion ]; then
        . /etc/bash_completion
    fi
fi