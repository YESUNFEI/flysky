<template>
  <div class='dialogContent' v-show="showContent">
    <transition name='fade'> 
      <div class='bg' @click="$emit('close')" v-show="show">
      </div>
    </transition>
    <transition name='closeDialog' @after-leave='showContent=false'>
      <div class='alert' v-show="show">
        <ul>
          <li> 
            <img src="http://aicixi.img-cn-shanghai.aliyuncs.com/20180109094808143_31.png" @click="$emit('close')"/>
            <span>我的卡片</span>
          </li>
          <li v-for="card in cardList">
            <div  @click="$emit('select', card.id)" class="cardSelect">
              <img :src="card.logo" class="cardLogo" />
              <div class="cardTips">
                <span>{{card.name}}</span> 
                <h6 class="citySupport" v-if="card.support">所在城市支持</h6>
              </div>
              <img class="selectImg" v-show="card.isSelect" src="http://aicixi.img-cn-shanghai.aliyuncs.com/20180109094941820_51.png"/>
            </div>
          </li>
          <li @click="intoCardList">
            <img id='addCard' src="http://aicixi.img-cn-shanghai.aliyuncs.com/20180109102149045_6.png" />
            <span>领取新卡</span>
            <img id='goCardList' src="http://aicixi.img-cn-shanghai.aliyuncs.com/20180108015116758_90.png" />
          </li>
        </ul>
      </div>
    </transition>
  </div>
</template>

<script>
  export default {
    name: 'cardDialog',
    data () {
      return {
        show: false,
        showContent: false
      }
    },
    props: [ 'control', 'cardList' ],
    watch: {
      control (newvalue) {
        if (newvalue) {
          this.showContent = true
          this.show = true
        } else {
          this.show = false
        }
      }
    },
    methods: {
      intoCardList () {
        let scope = this
        scope.$router.push({path: '/cardList'})
      }
    },
    created () {
      window.vv = this
    }
  }
</script>

<style scoped lang="scss">
  .fade-enter-active, .fade-leave-active {
    transition: opacity .2s
  }
  .fade-enter, .fade-leave-to /* .fade-leave-active in below version 2.1.8 */ {
    opacity: 0
  }

  .closeDialog-enter-active {
    animation: closeDialog-in .5s;
  }
  .closeDialog-leave-active {
    animation: closeDialog-in .2s reverse;
  }
  @keyframes closeDialog-in {
    0% {
      transform: translateY(100%);
    }
    100% {
      transform: translateY(0);
    }
  }


  @import '../common/style/variable.scss';
  .dialogContent {
    @include fill-all;
    height: 100vh;
    padding: 0;
    .bg {
      @include fill-all;
      background-color: rgba(0,0,0,.4);
    }
    .alert {
      width: 100%;
      height: 60%;
      background-color: white;
      position: fixed;
      bottom: 0;
      z-index: 100;

      ul {
        li {
          height: 5rem;
          padding-left:20px;
          .cardSelect {
            height: 100%;
            border-bottom: 1px solid #e7e7e7;
            font-size: 1.6rem;
            color: #333;
            position: relative;

            .cardTips {
              position: absolute;
              left: 4rem;
              top: 50%;
              transform: translateY(-50%);
              .citySupport {
                font-size: 1.4rem;
                color: #999;
                margin-top:0.5rem;
              }
            }

            .cardLogo {
              position: absolute;
              left: 0px;
              top: 50%;
              transform: translateY(-50%);
              width: 2.5rem;
              border-radius: 50%;
            }

            .selectImg {
              width: 1.8rem;
              position: absolute;
              right: 20px;
              top: 50%;
              transform: translateY(-50%);
            }
          }
        }

        li:first-child {
          padding:0;
          border-bottom: 1px solid #e7e7e7;
          text-align: center;
          position: relative;
          span {
            font-size: 1.8rem;
            color: #333;
            line-height: 5rem;
          }
          img {
            width: 1rem;
            position: absolute;
            left: 20px;
            top: 50%;
            transform: translateY(-50%);
          }
          
        }
        li:last-child {
          border-bottom: 1px solid #e7e7e7;
          text-align: left;
          position: relative;
          line-height: 5rem;
          span {
            font-size: 1.8rem;
            color: #333;
            margin-left: 3.5rem;
            display: inline-block;
          }
          #goCardList {
            width: 1rem;
            position: absolute;
            right: 20px;
            top: 50%;
            transform: translateY(-50%);
          }
          #addCard {
            width: 3rem;
            position: absolute;
            left: 20px;
            top: 50%;
            transform: translateY(-50%);
          }
        }
      }
    }
  }
</style>